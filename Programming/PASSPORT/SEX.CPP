#include <iostream.h>
#include <ctype.h>
#include "Sex.h"

Sex::Sex()
{
	Sex::SetSex();
}

void Sex::SetSex()
{
	do
	{
		cout<<"Enter gender : ";
		cin >>_Sex;
		_Sex=toupper(_Sex);
		if (_Sex!='F'&&_Sex!='M')
			cerr<<"Incorrect gender !!!"<<endl;
	}
	while(_Sex!='F'&&_Sex!='M');
}

char Sex::GetSex(void) const
{
	return _Sex;
}