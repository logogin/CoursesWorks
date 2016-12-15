//                       November/04/2000
//                      Dmitry Zavyalov (C)
//
// 1.31 ------------------------------------------------------------
//      Write a program that reads integer and determines and prints
// whether it is odd or even. (Hint: Use the modulus operator.
// An even number is a multiple of two. Any multiple of two leaves a
// remainder of zero when divided by 2.)
//------------------------------------------------------------------

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//.......................... BEGIN .................................
main(void) {
  clrscr();
  int Integer, Remainder;	    // variable opening
				
  cout <<"Input one integer: ";     // variable reading from streame
  cin >>Integer;
  cout <<endl;

  Remainder=Integer%2;		    // remainder calculation

  if (Remainder==1)                // result printing ...
    cout <<Integer
	 <<" is ODD number"
	 <<endl;
  else
    cout <<Integer
	 <<" is EVEN number"
	 <<endl;

  cout <<"\nPress ENTER to continue..."
       <<endl;
						// Pause ...
  getch();
  return 0;
}
//.......................... END ...................................