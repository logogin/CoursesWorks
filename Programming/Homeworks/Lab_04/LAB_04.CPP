// 00.00.2000 Dmitry Zavyalov (c)

#include "file.h"

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

main(void)
{
	clrscr();

	File Ob1(3,6), Ob2;

	Ob1.Print();
	Ob2.Print();
	Ob1=Ob1.Add(Ob2);
	Ob1.Print();

	cout<<endl;
	cout<<"Press any key to continue...";
	getch();
	return (0);
}