#include <iostream.h>
#include <string.h>
#include <windows.h>

void main()
{
	char date[20];
	int month;
	char day[3];
	char *months[12]={"Januar","Februar","March",
					  "April","May","June",
					  "July","August","September",
					  "October","November","December"};

	cout <<"Enter the date (mm/dd/yyyy) : ";
	cin >> date;
	month=atoi(date);
	day[0]=date[3];
	day[1]=date[4];
	day[2]='\x0';
	cout <<months[month-1]<<" "<<day<<", "<<date+6<<endl;
}