//                       November/04/2000
//                      Dmitry Zavyalov (C)
//
// 1.27 ------------------------------------------------------------
//      There are program that reads in the radius of a circle and
// prints the circle's diametr, circumference, and area. Use the
// constant value 3.14159 for Pi. Do these calculations in output
// statments. (Note: In this chapter, we have discussed only integers
// constants and variables. In Chapter 3 we will discuss floating
// point numbers, i.e., values that can have decimal points.)
//------------------------------------------------------------------

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define Pi 3.14159			// constant definition
//.......................... BEGIN .................................
main(void) {
  clrscr();
  float Radius;				// variable opening
                            // variable reading from streame
  cout <<"Input Radius of a circle: ";
  cin  >>Radius;   cout <<endl;
                                //negative and positive
  if (Radius >= 0) {		//variable check

// for positive variable 
    cout <<"Diametr is "	//Diametr calculation
	 <<2*Radius 	        //2*R
	 <<endl;

    cout <<"Circumference is "  //Circumference calculation
	 <<2 * Pi * Radius      //2*Pi*R
	 <<endl;

    cout <<"Area is "           //Area calculation
	 <<Pi * Radius * Radius //Pi*R*R
	 <<endl;
  }

// for negaitive variable printing ERROR message
  else cout <<"ERROR..." <<endl;

  cout <<"\nPress ENTER to continue..."
       <<endl;
						// Pause ...
  getch();
  return 0;
}
//.......................... END ...................................