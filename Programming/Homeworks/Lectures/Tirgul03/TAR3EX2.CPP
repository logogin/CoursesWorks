/*               Ex3 Tar2               */

/****************************************/
/*      Rational Numbers Operations.    */
/****************************************/

#include <iostream.h>
#include "Rational.h"

int main(void)
{
  Rational Rational1(2, 6);
  Rational Rational2(7, 8);
  Rational RationalResult;

  /*    Addition of 2 Rational Numbers.      */

  Rational1.PrintRational();
  cout << " + ";
  Rational2.PrintRational();
  RationalResult = Rational1.Addition(Rational2);
  cout << " = ";
  RationalResult.PrintRational();
  cout << " = ";
  RationalResult.PrintRationalAsFloat();
  cout << "\n\n";

  /*    Subtruction of 2 Rational Numbers.      */

  Rational1.PrintRational();
  cout << " - ";
  Rational2.PrintRational();
  RationalResult = Rational1.Subtraction(Rational2);
  cout << " = ";
  RationalResult.PrintRational();
  cout << " = ";
  RationalResult.PrintRationalAsFloat();
  cout << "\n\n";

  /*    Multiplication of 2 Rational Numbers.      */

  Rational1.PrintRational();
  cout << " x ";
  Rational2.PrintRational();
  RationalResult = Rational1.Multiplication(Rational2);
  cout << " = ";
  RationalResult.PrintRational();
  cout << " = ";
  RationalResult.PrintRationalAsFloat();
  cout << "\n\n";

  /*    Division of 2 Rational Numbers.      */

  Rational1.PrintRational();
  cout << " / ";
  Rational2.PrintRational();
  RationalResult = Rational1.Division(Rational2);
  cout << " = ";
  RationalResult.PrintRational();
  cout << " = ";
  RationalResult.PrintRationalAsFloat();
  cout << endl;

  return 0;
}