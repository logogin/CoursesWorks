// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#include <iostream.h>
#include "passport.h"

Passport::Passport( void )
{
	Person_BirthDay;
	Person_FullName;
	Person_Sex;

//	SetLastExit();
//	SetLastReturn();

}

/*/
void SetLastExit( void )
{

}

void SetLastReturn( void )
{
}
/*/

int  Passport::GetDay( void ) const
{
	return( Person_BirthDay.GetDay() );
}

int  Passport::GetMonth( void ) const
{
	return( Person_BirthDay.GetMonth() );
}

int  Passport::GetYear( void ) const
{
	return( Person_BirthDay.GetYear() );
}


char Passport::GetPSex( void ) const
{
	return ( Person_Sex.GetPSex() );
}

void Passport::GetFullName( char *First, char *Last ) const
{
	Person_FullName.GetFirstName( First );
	Person_FullName.GetLastName( Last );
}
