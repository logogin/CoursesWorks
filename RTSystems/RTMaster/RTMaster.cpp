#include <tchar.h>
#include <windows.h>
#include <stdio.h>

#define MAX_FRAGMENT 1024
#define HEAP_INITSIZE 512

void usage(void)
{
	_tprintf(_T("Usage: RTMaster <filename> <procnumber>\n\n"));
}

void _tmain(int argn,TCHAR *argv[])
{
	DWORD dwSlavesNumber;
	TCHAR fileName[MAX_PATH];
	if (argn!=3)
	{
		usage();
		return;
	}

	HANDLE hFile;
	HANDLE hMapping;
	LPVOID pMappingData;
	HANDLE hHeap;
	LPVOID pData;
	HANDLE hStartEvent;
	HANDLE hGuardMutex;
	HANDLE hMasterEvent;
	HANDLE hSlaveEvent;
	HANDLE hStdOut;

	CopyMemory(fileName,argv[1],(_tcslen(argv[1])+1)*sizeof(TCHAR));
	dwSlavesNumber=_ttoi(argv[2])-1;

	/********* Get file handler ********/
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

	LARGE_INTEGER liMappingSize;
	liMappingSize.QuadPart=MAX_FRAGMENT*sizeof(TCHAR);
	/******** Get shared memory handle **********/
	hMapping=CreateFileMapping((HANDLE)0xFFFFFFFF,NULL,PAGE_READWRITE,
		liMappingSize.HighPart,liMappingSize.LowPart,_T("RT Course FM ASS1"));
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

	DWORD dwDataSize;
	/********* Read data from file**********/
	ReadFile(hFile,(PDWORD)pMappingData+1,GetFileSize(hFile,NULL),&dwDataSize,NULL);
	/******* Write data size first*************/
	CopyMemory(pMappingData,&dwDataSize,sizeof(dwDataSize));

	/********** Get heap handler **********/
	hHeap=HeapCreate(HEAP_GENERATE_EXCEPTIONS | HEAP_NO_SERIALIZE,
		MAX_FRAGMENT*sizeof(TCHAR),0);
	if (hHeap==NULL)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}

	pData=HeapAlloc(hHeap,HEAP_GENERATE_EXCEPTIONS | HEAP_NO_SERIALIZE,
		MAX_FRAGMENT*sizeof(TCHAR));
	CopyMemory(pData,(PDWORD)pMappingData+1,dwDataSize);

	hGuardMutex=CreateMutex(NULL,FALSE,_T("GUARD_MUTEX"));
	if (hGuardMutex==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	hMasterEvent=CreateEvent(NULL,FALSE,FALSE,_T("MASTER_EVENT"));
	if (hMasterEvent==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	hSlaveEvent=CreateEvent(NULL,TRUE,TRUE,_T("SLAVE_EVENT"));
	if (hSlaveEvent==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}

	/********** Slaves can now start their job ***********/
	SetEvent(hStartEvent);
	
	hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut==INVALID_HANDLE_VALUE)
	{
		LPTSTR lpvSysMsg=NULL;
		FormatMessage (FORMAT_MESSAGE_ALLOCATE_BUFFER |	FORMAT_MESSAGE_FROM_SYSTEM 
			| FORMAT_MESSAGE_IGNORE_INSERTS,NULL,GetLastError(),
			MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpvSysMsg,0,NULL);
		_tprintf(_T("%s\n\n"),lpvSysMsg);
		return;
	}
	DWORD dwCount;

	_tprintf(_T("============ Part 1 ==============\n"));
	WriteFile(hStdOut,pData,dwDataSize,&dwCount,NULL);

	_tprintf(_T("\n==================================\n"));
	for (int i=0; i<dwSlavesNumber; i++)
	{

		_tprintf(_T("Waiting...\n"));
		/********* Waiting for signal from slaves *********/
		WaitForSingleObject(hMasterEvent,INFINITE);
		CopyMemory(&dwDataSize,pMappingData,sizeof(DWORD));
		CopyMemory(pData,(PDWORD)pMappingData+1,dwDataSize);

		/********* Slaves can now continue **************/
		SetEvent(hSlaveEvent);
		_tprintf(_T("============ Part %d ==============\n"),i+2);
		WriteFile(hStdOut,pData,dwDataSize,&dwCount,NULL);
		_tprintf(_T("\n==================================\n"));
	}

	UnmapViewOfFile(pMappingData);
	CloseHandle(hMapping);
	CloseHandle(hFile);
	HeapDestroy(hHeap);
	CloseHandle(hStartEvent);
	CloseHandle(hGuardMutex);
	CloseHandle(hMasterEvent);
	CloseHandle(hSlaveEvent);
	CloseHandle(hFile);
	CloseHandle(hStdOut);
}