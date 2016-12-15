//                       November/04/2000
//                      Dmitry Zavyalov (C)
//
// 1.36 ------------------------------------------------------------
//      Write a program that inputs a five-digit number and
// separates this number into its individual digits.
// [ 4 2 3 3 9     ]
//------------------------------------------------------------------

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//.......................... BEGIN .................................
main(void) {
  clrscr();
  long Integer;			// variable opening
				// variable reading from streame
  cout <<"Input five-digit integer number: ";
  cin >>Integer;
  cout <<endl;
                                
  cout <<Integer/10000          // First digit finding
       <<" ";                   // and printing to screen.
  cout <<Integer%10000/1000	// Second digit finding
       <<" ";                   // and printing to screen.
  cout <<Integer%1000/100	// Third digit finding
       <<" ";                   // and printing to screen.
  cout <<Integer%100/10		// Fourth digit finding
       <<" ";                   // and printing to screen.
  cout <<Integer%10/1		// Last digit finding
       <<"\n";                  // and printing to screen.
				// Pause ...
  cout <<"\nPress ENTER to continue..."
       <<endl;

  getch();
  return 0;
}
//.......................... END ...................................