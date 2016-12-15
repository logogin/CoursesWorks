#include <iostream.h>
#include <string.h>
#include "Passport.h"

Passport::Passport():PersonName(),
					BirthDate("Birth Date"),
					PersonSex(),
					LastExit("Last Exit"),
					LastReturn("Last Return")
{
	cout<<endl;
}

bool Passport::Compare(Passport &Person) const
{
	bool flag=true;
	if (strcmp(PersonName.GetFirstName(),Person.PersonName.GetFirstName()))
		flag=false;
	if (strcmp(PersonName.GetLastName(),Person.PersonName.GetLastName()))
		flag=false;
	if (BirthDate.GetDay()!=Person.BirthDate.GetDay())
		flag=false;
	if (BirthDate.GetMonth()!=Person.BirthDate.GetMonth())
		flag=false;	
	if (BirthDate.GetYear()!=Person.BirthDate.GetYear())
		flag=false;
	if (LastExit.GetDay()!=Person.LastExit.GetDay())
		flag=false;
	if (LastExit.GetMonth()!=Person.LastExit.GetMonth())
		flag=false;
	if (LastExit.GetYear()!=Person.LastExit.GetYear())
		flag=false;
	if (LastReturn.GetDay()!=Person.LastReturn.GetDay())
		flag=false;
	if (LastReturn.GetMonth()!=Person.LastReturn.GetMonth())
		flag=false;
	if (LastReturn.GetYear()!=Person.LastReturn.GetYear())
		flag=false;
	if (PersonSex.GetSex()!=Person.PersonSex.GetSex())
		flag=false;
	return flag;
}