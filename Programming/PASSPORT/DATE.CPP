#include <iostream.h>
#include "date.h"

Date::Date(char *Title)
{
	Date::SetDate(Title);
}

void Date::SetDate(char *Title)
{
	do
	{
		cout<<"Enter the Date of "<<Title<<" :"<<endl;
		cout<<" Day : ";
		cin>>Day;
		cout<<" Month : ";
		cin>>Month;
		cout<<" Year : ";
		cin>>Year;
		if (!Date::CheckDate())
			cerr<<"Incorrect Date !!!"<<endl;
	}
	while (!Date::CheckDate());
}

void Date::SetDay(int sDay)
{
	Day=sDay;
	if (!Date::CheckDate())
		Day=1;
}

void Date::SetMonth(int sMonth)
{
	Month=sMonth;
	if (!Date::CheckDate())
		Month=1;
}

void Date::SetYear(int sYear)
{
	Year=sYear;
	if (!Date::CheckDate())
		Year=2001;
}

void Date::PrintDate(void)
{
	if (Day<10)
		cout<<'0';
	cout<<Day<<'.';
	if (Month<10)
		cout <<'0';
	cout <<Month<<'.'<<Year<<flush;
}

void Date::GetDate(int &gDay,int &gMonth,int &gYear)
{
	gDay=Day;
	gMonth=Month;
	gYear=Year;
}

int Date::GetDay(void) const
{
	return Day;
}

int Date::GetMonth(void) const
{
	return Month;
}

int Date::GetYear(void) const
{
	return Year;
}

bool Date::CheckDate(void)
{
	if (Month>0&&Month<13&&Day>0&&Day<=daypermonth[Month-1]&&Year>0)
		return true;
	else
		return false;
}