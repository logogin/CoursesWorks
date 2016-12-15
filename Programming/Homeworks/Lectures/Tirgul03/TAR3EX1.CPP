/*               Ex3 Tar1               */

/****************************************/
/*       Complex Numbers Operations.    */
/****************************************/

#include <iostream.h>
#include "Complex1.h"

int main(void)
{
  Complex Complex1(1, 7);
  Complex Complex2(9, 2);

  /*    Add 2 Complex Numbers And Print The Result.   */

  Complex1.PrintComplexNumber();
  cout << " + ";
  Complex2.PrintComplexNumber();
  cout << " = ";
  Complex1.ComplexAddition(Complex2);
  Complex1.PrintComplexNumber();
  cout << endl;

  /*  Subtruct 2 Complex Numbers And Print The Result. */

  Complex1.SetComplexNumber(10.0, 1.0);
  Complex2.SetComplexNumber(11.0, 5.0);
  Complex1.PrintComplexNumber();
  cout << " - ";
  Complex2.PrintComplexNumber();
  cout << " = ";
  Complex1.ComplexSubtraction(Complex2);
  Complex1.PrintComplexNumber();
  cout << endl;

  return 0;
}