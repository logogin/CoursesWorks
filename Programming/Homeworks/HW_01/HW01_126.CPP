//                       November/04/2000
//                      Dmitry Zavyalov (C)
//
// 1.26 ------------------------------------------------------------
//      Write a program that inputs three integers from the
// keyboard, and prints the sum, averag, product, smallest
// and largest of these numbers. The screen dialogue should
// appear as follows:
//  ____________________________________________________
// |							|
// |  Input three different integers: 13 27 14		|
// |  Sum is 54						|
// |  Average is 18					|
// |  Product is 4914					|
// |  Smallest is 13					|
// |  Largest is 27					|
// |____________________________________________________|
//
//------------------------------------------------------------------

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//.......................... FNUNCTIONs ............................
// Function that return the largest value from Value_01 or Value_02.
int Max(int Value_01, int Value_02)
  {
     return((Value_01 > Value_02) ? Value_01 : Value_02 );
  }

// Function that return the Smallest value from Value_01 or Value_02
int Min(int Value_01, int Value_02)
  {
     return((Value_01 < Value_02) ? Value_01 : Value_02 );
  }

//.......................... BEGIN .................................
main(void)
{
  clrscr();
  int Integer_01, Integer_02, Integer_03; // variables opening
  unsigned long Product;                  // for "Product" result

  cout <<"Input three defferent integers: ";
  cin  >>Integer_01	// reading variable value from stream
       >>Integer_02	//   ---   //   ---
       >>Integer_03;    //   ---   //   ---

  cout <<"Sum is "                       //printing SUM to screen
       <<Integer_01+Integer_02+Integer_03
       <<endl;

  cout <<"Average is "			//printing Average to screen
       <<(Integer_01+Integer_02+Integer_03)/3.0
       <<endl;
                                        //PRODUCT calculating
  Product=Integer_01*Integer_02*Integer_03;
					
  cout <<"Product is "                  //printing PRODUCT to screen
       <<Product
       <<endl;
                                        //finding and printing
  cout <<"Smallest is "			//"Smallest int" to screen
       <<Min(Min(Integer_01,Integer_02),Integer_03)
       <<endl;
                                        //finding and printing
  cout <<"Largest is "                  //"Largest integer" to screen
       <<Max(Max(Integer_01,Integer_02),Integer_03)
       <<endl;

  cout <<"\nPress ENTER to continue..."
       <<endl;
                                        // Pause ...
  getch();
  return 0;
}
//.......................... END ...................................
