// 29.01.2001 Dmitry Zavyalov (c)
//
// Program " MyStruct.h "

#include <conio.h>
#include <string.h>
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

int main( void )
{
	ifstream InpFile( "Input.txt", ios::in );
	ofstream OutFile;
	char Buffer[255] = {' '}, FileName[11] = {' '},
		 Buffer2[255] = {' '},
		 Buffer3[255] = {' '};

	int Finder, Finder2;		// flag

//--------------------------- File Name Checking ------------------
	InpFile>>Buffer;
	if( strlen(Buffer) > 8 ) {
		cout<<"\nCurrent Filename length is "
			<<strlen(Buffer)
			<<"\nMax Filename length is 8 letters...\n"
			<<endl;
		exit( 0 );
	}

//----------------------------- File Open -------------------------
	strcpy( FileName, Buffer );
	strcat( FileName, ".h");
	OutFile.open( FileName, ios::out );

	OutFile	<<"struct "
			<<Buffer
			<<"\n{\n";

	while( !InpFile.eof() ) {
		InpFile>>Buffer;
		Finder = 1;
		Finder2 =1;

		if( !strcmp( Buffer, "int" ) ) Finder = 0;

		if( !strcmp( Buffer, "unsigned" ) && Finder ){
			Finder = 0;
			InpFile>>Buffer2;
			if( !strcmp( Buffer2, "short" ) )Finder2 = 0;
			if( !strcmp( Buffer2, "char") && Finder2 ) Finder2 = 0;
			if( Finder2 ) {
				cout<<"\nError in input file ...\n"
					<<endl;
				exit( 0 );
			}
		}

		if( !strcmp( Buffer, "MyType" ) && Finder  ) Finder = 0;

		if( Finder ) {
			cout<<"\nError in input file ...\n"
				<<endl;
			exit( 0 );
		}

		if( (strlen(Buffer) + strlen(Buffer2) + 1) >15 ){
			cout<<"\nVariable Type name largest 15 letters\n"
				<<endl;
			exit( 0 );
		}

		InpFile>>Buffer3;

		OutFile	<<"		"
				<<Buffer
				<<" "
				<<Buffer2
				<<"		"
				<<Buffer3
				<<"		;\n";

		Buffer[0]=Buffer2[0]=Buffer3[0]=' ';
		Buffer[1]=Buffer2[1]=Buffer3[1]='\0';
	}
	OutFile<<"}		;";

//----------------------------- File Closing & Programm Termination
	cout<<"\nFiles Processing OK ....\n"
		<<endl;
	getch();
	InpFile.close( );
	OutFile.close( );
	return( 0 );
}
