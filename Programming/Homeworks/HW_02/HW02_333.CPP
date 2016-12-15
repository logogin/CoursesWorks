// 16.11.2000 Dmitry Zavyalov (c)
//
// 3.33 - qualityPoints function ...

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int qualityPoints(const int * const);

main(void)
{
	clrscr();

	int StudentsAverage=0, QPValue;

	cout<<"Please, Insert Students Average : ";
	cin >>StudentsAverage;

	if(StudentsAverage<0 || StudentsAverage>100)	cout<<"ERROR!"<<endl;

	else{
		cout<<"Students Quality Points Are : ";
		QPValue=qualityPoints(&StudentsAverage);
		if(QPValue<0) cout<<"ERROR!";
		else cout<<QPValue;
		cout<<endl;
	}

	cout<<"Press any key to continue...";
	getch();
	return (0);
}

int qualityPoints(const int * const pStAver)
{
	int RetValue=0;

	if( *pStAver<=100 && *pStAver>=90 ) RetValue=4;
	if( *pStAver<=89  && *pStAver>=80 ) RetValue=3;
	if( *pStAver<=79  && *pStAver>=70 ) RetValue=2;
	if( *pStAver<=69  && *pStAver>=60 ) RetValue=1;
	if( *pStAver<=59  && *pStAver>= 0 ) RetValue=0;

	return (RetValue);
}