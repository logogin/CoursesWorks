// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#include <iostream.h>
#include "sex.h"

Sex::Sex()
{
	SetPSex();
}

void Sex::SetPSex( void )
{
	char PersonInput;
	cPSex=' ';
	do {
		cout<<"Enter Person Sex :";
		cin >>PersonInput;
		if( PersonInput=='F' || PersonInput=='f' ) cPSex='F';
		if( PersonInput=='M' || PersonInput=='m' ) cPSex='M';
		if( PersonInput==' ' )  cout<<"\nPlaese, Use only F/f or M/m keys ..." <<endl;
	} while( cPSex==' ' );
}

char Sex::GetPSex( void ) const
{
	return (cPSex);
}
