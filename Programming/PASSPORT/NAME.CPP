#include <iostream.h>
#include <string.h>
#include "name.h"

Name::Name()
{
	char string[80];
	cout <<"Enter Fitst Name : ";
	cin>>string;
	FirstName=strdup(string);
	cout<<"Enter Last Name : ";
	cin>>string;
	LastName=strdup(string);
}

Name::~Name()
{
	delete []FirstName;
	delete []LastName;
}

void Name::SetFirstName(char *sFirstName)
{
	FirstName=strdup(sFirstName);
}

void Name::SetLastName(char *sLastName)
{
	LastName=strdup(sLastName);
}

void Name::PrintFullName(void)
{
	cout<<FirstName<<" "<<LastName<<flush;
}

void Name::GetFullName(char *gFirstName,char *gLastName)
{
	gFirstName=strdup(FirstName);
	gLastName=strdup(LastName);
}

char *Name::GetFirstName() const
{
	return strdup(FirstName);
}

char *Name::GetLastName() const
{
	return strdup(LastName);
}