// 14.12.2000 Dmitry Zavyalov (c)
//
// Home Work No4 (class Passport)

#ifndef Name_H
#define Name_H

class Name
{
private:
	char *szFirstName;
	char *szLastName;

public:
	Name( void );

	void SetFirstName(void);
	void SetLastName(void);

	void GetFullName( char*, char* );
	void GetFirstName( char* ) const;
	void GetLastName( char* ) const;

	void PrintFullName( void );
};

#endif
