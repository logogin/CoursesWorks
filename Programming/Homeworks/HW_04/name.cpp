// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#include <iostream.h>
#include <string.h>
#include <stdlib.h>
#include "name.h"

Name::Name()
{
	SetFirstName();
	SetLastName();
}

void Name::SetFirstName(void)
{
	char Buffer[256]={' '};

	do {
		cout<<"Enter First Name : ";
		cin >>Buffer;
		szFirstName=(char*) malloc( strlen(Buffer)*sizeof(char) );
		strcpy( szFirstName, Buffer );
	} while( strlen(Buffer)<3 );
}

void Name::SetLastName(void)
{
	char Buffer[256]={' '};

	do {
		cout<<"Enter Last Lame : ";
		cin >>Buffer;
		szLastName=(char*) malloc( strlen(Buffer)*sizeof(char) );
		strcpy( szLastName, Buffer );
	} while( strlen(Buffer)<3 );
}

void Name::PrintFullName( void )
{
	cout<<szFirstName
		<<" "
		<<szLastName
		<<endl;
}

void Name::GetFullName( char *FN, char *LN )
{
	strcpy( FN, szFirstName );
	strcpy( LN, szLastName );
}

void Name::GetFirstName( char *FN ) const
{
	strcpy( FN, szFirstName );
}

void Name::GetLastName( char *LN ) const
{
	strcpy( LN, szLastName );
}
