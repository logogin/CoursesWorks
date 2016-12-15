// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#include <iostream.h>
#include "date.h"

Date::Date( void )
{
	SetDate();
}

void Date::SetDate( void )
{
	int day, month, year;

	do {
		cout<<"Plese, Input Person Birthday Date"
			<<endl;
		day   = SetDay();
		month = SetMonth();
		year  = SetYear();

	} while ( !CheckDate( day, month, year ) );

	iDay   = day;
	iMonth = month;
	iYear  = year;
}

int Date::SetDay()
{
	int Ret;
	cout<<"Please, Input Day : ";
	cin >>Ret;
	return( Ret );
}

int  Date::SetMonth()
{
	int Ret;
	cout<<"Please, Input Month : ";
	cin >>Ret;
	return( Ret );
}

int  Date::SetYear()
{
	int Ret;
	cout<<"Please, Input Year : ";
	cin >>Ret;
	return( Ret );
}

int  Date::CheckDate( int date, int month, int year )
{
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int is_leap_year;	//flag
										//check if the inputed month exist
	if( (month < 1) || (month > 12) ){
		cout<<"\nERROR: Invalid MONTH value.\n"
			<<endl;
		return( 0 );
	}
										//check if year is leap year
	is_leap_year = ( year % 4 ==0 ) && ( year % 100 != 0 ) || ( year % 400 == 0 );

										//check if the inputed day of the month exist
	if( is_leap_year && (month == 2) )	//february of the leap year
		if( ( date < 1 ) || ( date > (days[month - 1] + 1) ) ) {
			cout<<"\nERROR: Invalid DAY value.\n"
				<<endl;
			return( 0 );
		}
										//check if the inputed day of the month exist
	else
		if( ( date < 1 ) || ( date > days[month - 1] ) ) {
			cout<<"\nERROR: Invalid DAY value.\n"
				<<endl;
			return( 0 );
		}

	if( year<1000 ) {
		cout<<"\nERROR: Invalid YEAR value.\n"
			<<endl;
		return( 0 );
	}

	return( 1 );
}

void Date::PrintDate( void)
{
	cout<<( iDay<10 ? "0":"")
		<<iDay
		<<"."
		<<( iMonth<10 ? "0":"")
		<<iMonth
		<<"."
		<<iYear
		<<endl;
}

int  Date::GetDay( void ) const
{
	return( iDay );
}

int  Date::GetMonth( void ) const
{
	return( iMonth );
}

int  Date::GetYear( void ) const
{
	return( iYear );
}

void Date::GetDate( int *day, int *month, int *year )
{
	*day   = GetDay();
	*month = GetMonth();
	*year  = GetYear();
}
