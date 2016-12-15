#include <iostream.h>
#include "Passport.h"

bool read_data(Passport *person)
{
	char flag=0;
	Passport SearchData;
	for (int i=0; i<5; i++)
		if (SearchData.Compare(person[i]))
			flag=i+1;
	cout<<"Person index is : "<<(int)flag<<endl;
	return flag;
}

bool main()
{
	Passport Person[5];
	cout<<endl<<"Enter Data for search "<<endl;
	return read_data(Person);
}
