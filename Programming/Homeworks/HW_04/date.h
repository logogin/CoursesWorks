// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#ifndef Date_H
#define Date_H

class Date
{
private:
	int iDay,
		iMonth,
		iYear;

public:
	Date( void );

	void SetDate( void );
	int SetDay( void);
	int SetMonth( void );
	int SetYear( void );

	void GetDate( int*, int*, int* );
	int  GetDay( void ) const;
	int  GetMonth( void ) const;
	int  GetYear( void ) const;

	int  CheckDate( int, int, int );
	void PrintDate( void);
};

#endif
