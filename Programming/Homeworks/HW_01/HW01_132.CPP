//                       November/04/2000
//                      Dmitry Zavyalov (C)
//
// 1.32 ------------------------------------------------------------
//      Write a program that reads in two integers and determines
// and prints if the first is a multiple of the second.
// (Hint: Use the modulus operator.)
//------------------------------------------------------------------

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//.......................... BEGIN .................................
main(void) {
  clrscr();			// variable opening
  int Integer_01,               // Integer variables
      Integer_02, 
      Remainder;                // remainder ...

  cout <<"Input two integers: ";    // variable reading from streame
  cin >>Integer_01
      >>Integer_02;
  cout <<endl;
                                // remainder calculation
  Remainder = Integer_02 % Integer_01;

  if (Remainder==0)             // result printing if ...
    cout <<Integer_01           
	 <<" is a multiple of "
	 <<Integer_02
	 <<endl;
  else
    cout <<Integer_01
	 <<" isn't a multiple of "
	 <<Integer_02
	 <<endl;

  cout <<"\nPress ENTER to continue..."
       <<endl;
					// Pause ...
  getch();
  return 0;
}
//.......................... END ...................................