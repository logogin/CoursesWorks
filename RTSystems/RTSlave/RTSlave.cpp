#include <tchar.h>
#include <windows.h>
#include <stdio.h>

#define MAX_FRAGMENT 1024

void usage(void)
{
	_tprintf(_T("Usage: RTSlave <filename>\n\n"));
}


void _tmain(int argn,TCHAR *argv[])
{
	if (argn!=2)
	{
		usage();
		return;
	}
	TCHAR fileName[MAX_PATH];
	CopyMemory(fileName,argv[1],(_tcslen(argv[1])+1)*sizeof(TCHAR));

	HANDLE hFile;
	HANDLE hCurFile;
	TCHAR *pCurData=NULL;
	HANDLE hHeap;
	HANDLE hStartEvent;
	HANDLE hMapping;
	LPVOID pMappingData=NULL;
	HANDLE hMasterEvent;
	HANDLE hGuardMutex;
	HANDLE hSlaveEvent;
	HANDLE hTryEvent;
	HANDLE hStdOut;

	/********* Open File **********/
	hFile=CreateFile(fileName,GENERIC_READ,0,NULL,
		OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	if (hFile==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}

	/******* Map File to memory ********/
	hCurFile=CreateFileMapping(hFile,NULL,PAGE_READONLY,0,0,NULL);
	if (hCurFile==NULL)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}

	pCurData=(TCHAR *)MapViewOfFile(hCurFile,FILE_MAP_READ,0,0,0);
	
	DWORD dwLineSize=0;
	DWORD dwBlockSize=GetFileSize(hFile,NULL)/sizeof(TCHAR);
	/********* Calculate line size ********/
	while(pCurData[dwLineSize++]!=0x0A&&dwLineSize<dwBlockSize);
	_tprintf(_T("File Content:\n\n"));

	DWORD dwCount;
	/******* Get Standart Handler *********/
	hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	WriteFile(hStdOut,pCurData,dwBlockSize*sizeof(TCHAR),&dwCount,NULL);

	_tprintf(_T("\n==========\n"));	
	dwLineSize=dwLineSize*sizeof(TCHAR);

	/******** Get Heap *********/
	hHeap=HeapCreate(HEAP_GENERATE_EXCEPTIONS | HEAP_NO_SERIALIZE,dwLineSize,0);
	if (hHeap==NULL)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	LPVOID pFirstLine=HeapAlloc(hHeap,HEAP_GENERATE_EXCEPTIONS | HEAP_NO_SERIALIZE,dwLineSize);
	CopyMemory(pFirstLine,pCurData,dwLineSize);
	
	hStartEvent=CreateEvent(NULL,TRUE,FALSE,_T("START_SLAVES_EVENT"));
	if (hStartEvent==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}

	/******** Wait for master ********/
	_tprintf(_T("Waiting for master...\n"));
	WaitForSingleObject(hStartEvent,INFINITE);
	
	/******** Get shared memory **********/
	hMapping=OpenFileMapping(FILE_MAP_ALL_ACCESS,TRUE,_T("RT Course FM ASS1"));
	if (hMapping==NULL)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	pMappingData=MapViewOfFile(hMapping,FILE_MAP_ALL_ACCESS,0,0,0);

	
	hMasterEvent=OpenEvent(EVENT_ALL_ACCESS,FALSE,_T("MASTER_EVENT"));
	if (hMasterEvent==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	hGuardMutex=OpenMutex(MUTEX_ALL_ACCESS,FALSE,_T("GUARD_MUTEX"));
	if (hGuardMutex==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	hSlaveEvent=OpenEvent(EVENT_ALL_ACCESS,FALSE,_T("SLAVE_EVENT"));
	if (hSlaveEvent==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	HANDLE pGuards[2]={hGuardMutex,hSlaveEvent};

	hTryEvent=CreateEvent(NULL,TRUE,TRUE,_T("TRY_EVENT"));
	if (hTryEvent==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}

	DWORD dwDataSize;
	BOOL bTryed=FALSE;
	BOOL bFinished=FALSE;
	while (!bFinished)
	{
		_tprintf(_T("Waiting...\n"));
		/******* Preventing process from reading more than ones same data *******/
		if (bTryed)
		{
			WaitForSingleObject(hTryEvent,INFINITE);
			bTryed=FALSE;
		}
		WaitForMultipleObjects(2,pGuards,TRUE,INFINITE);
		CopyMemory(&dwDataSize,pMappingData,sizeof(DWORD));
		_tprintf(_T("[%s]\n\n"),pFirstLine);
		if (!memcmp(pFirstLine,
			(PBYTE)pMappingData+(dwDataSize-dwLineSize)+sizeof(DWORD),dwLineSize))
		{
			dwBlockSize*=sizeof(TCHAR);
			CopyMemory(pMappingData,&dwBlockSize,sizeof(DWORD));
			CopyMemory((PDWORD)pMappingData+1,pCurData,dwBlockSize);
			bFinished=TRUE;
			/******** No one slave process can enter ********/
			ResetEvent(hSlaveEvent);
			/******** Others can now try to read memory *********/
			SetEvent(hTryEvent);
			/******** Master can now output data *********/
			SetEvent(hMasterEvent);
			
		}
		else
		{
			bTryed=TRUE;
			/***** Alredy tryed ********/
			ResetEvent(hTryEvent);
		}

		ReleaseMutex(hGuardMutex);
	}
	
	UnmapViewOfFile(pMappingData);
	CloseHandle(hMapping);
	UnmapViewOfFile(pCurData);
	CloseHandle(hCurFile);
	CloseHandle(hFile);
	CloseHandle(hStdOut);
	HeapDestroy(hHeap);
	CloseHandle(hStartEvent);
	CloseHandle(hMasterEvent);
	CloseHandle(hSlaveEvent);
	CloseHandle(hTryEvent);
	CloseHandle(hGuardMutex);
}