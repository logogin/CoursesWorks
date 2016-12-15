// 16.11.2000 Dmitry Zavyalov (c)
//
// 5.10 - Write single statement that prforms the indicated task.

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


main(void)
{
	clrscr();

	long value1 = 20000;
	long value2;

	long *lPtr;  	// a) the variable is a pointer to an object
			//    of type long
	lPtr=&value1; 	// b) the address of value1 assigned to pointer

	cout<<*lPtr	// c) print the value of the object pointed to
	    <<endl;	//    by lPtr
	value2=(*lPtr); // d) the value of the object pointed to by
			//    lPtr assigned to value2
	cout<<value2	// e) print the value of value2
	    <<endl;
	cout<<(&value1)	// f) printing the address of value1
	    <<endl;
	cout<<lPtr	// g) printing the address stored in lPtr;
	    <<endl;	//    YES!

	cout<<"Press any key to continue...";
	getch();
	return (0);
}