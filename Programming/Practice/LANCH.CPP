#include <stdio.h>
#include <conio.h>
 void main ()
{
  char months[]={31,28,31,30,31,31,31,30,30,31,30,31};
  int day,month,year;
  int hour,minutes,sec,flight;
  clrscr();
  printf("Enter the date (dd/mm/yyyy) : ");
  scanf("%d/%d/%d",&day,&month,&year);

  printf("Enter the time of lanch (hh:mm:ss)  ");
  scanf("%d:%d:%d",&hour,&minutes,&sec);

  printf("Enter the time of flight in sec.  ");
  scanf("%d",&flight);
  sec+=flight;
  minutes+=sec/60;
  sec%=60;
  hour+=minutes/60;
  minutes%=60;
  day+=hour/24;
  hour%=24;
  if (month==2&&year%4==0)
	{
	 if (day>(months[month-1]+1))
	   {
	    day%=months[month-1]+1;
	    month++;
	   }
	}
   else
	{
	 if (day>(months[month-1]))
	   {
	    day%=months[month-1];
	    month++;
	   }
	}

  printf("\nTime of departure : %d:%d:%d\n",hour,minutes,sec);
  printf("Date of departure : %d/%d/%d",day,month,year);
  getch();
}
