//                       November/04/2000
//                      Dmitry Zavyalov (C)
//
// 1.30 ------------------------------------------------------------
//      Write a program that reads in five integers and determines
// and prints the lapgest and the smallest integers in the group.
// Use only the programming techniques you learned in this chapter.
//------------------------------------------------------------------

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define Size 5				// constant definition
//.......................... BEGIN .................................
main(void) {
  clrscr();
					// variable opening
  int IntArray[Size],	// Integer number Array with defined size
      Counter,          // Cycle counter
      ptrLarg =0,       // Array pointer to Field with largest var.
      ptrSmall=0;       // Array pointer to Field with smallest var.
				// variable reading from streame
  cout <<"Input five different integers: ";
  for(Counter=0; Counter<Size; Counter++){
    cin >>IntArray[Counter];
  }
  cout <<endl;
			// finding largest and smallest variables
  for(Counter=0; Counter<(Size-1); Counter++){
    if(IntArray[Counter]<IntArray[Counter+1]) ptrLarg =Counter+1;
    if(IntArray[Counter]>IntArray[Counter+1]) ptrSmall=Counter+1;
  }
					//printing results
  cout <<"Largest  Integer is "
       <<IntArray[ptrLarg]
       <<endl;

  cout <<"Smallest Integer is "
       <<IntArray[ptrSmall]
       <<endl;

  cout <<"\nPress ENTER to continue..."
       <<endl;
						// Pause ...
  getch();
  return 0;
}
//.......................... END ...................................