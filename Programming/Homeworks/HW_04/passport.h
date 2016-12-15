// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#ifndef Pasport_H
#define Pasport_H

#include "date.h"
#include "name.h"
#include "sex.h"

class Passport
{
private:
	const Name Person_FullName;
	const Date Person_BirthDay;
	const Sex  Person_Sex;

//	Date LastExit;
//	Date LastReturn;

public:
	Passport( void );
//	void SetLastExit( void );
//	void SetLastReturn( void );

	int  GetDay( void ) const;
	int  GetMonth( void ) const;
	int  GetYear( void ) const;

	char GetPSex( void ) const;

	void GetFullName( char*, char* ) const;
};

#endif
