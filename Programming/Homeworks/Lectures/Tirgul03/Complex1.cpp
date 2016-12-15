#include <iostream.h>
#include "Complex1.h"

/*        Constructor - Initiation of Parameters.      */

Complex::Complex(double dReal,
                 double dImaginery)
{
  SetComplexNumber(dReal,
                   dImaginery);
}

/*    Set New Value to a Complex Numbers.    */

void Complex::SetComplexNumber(double dReal,
                               double dImaginery)
{
  dRealPart = dReal;
  dImagineryPart = dImaginery;
}

/*     Addition Between 2 Complex Numbers,     */
/*                and Reduction.               */
/*      The Output Saved in AdditionResult.    */

void Complex::ComplexAddition(const Complex &c_rSecondNumber)
{
  dRealPart += c_rSecondNumber.dRealPart;
  dImagineryPart += c_rSecondNumber.dImagineryPart;
}

/*   Subtruction Between 2 Complex Numbers,    */
/*                and Reduction.               */
/*     The Output Saved in SubtructResult.     */

void Complex::ComplexSubtraction(const Complex &c_rSecondNumber)
{
  dRealPart -= c_rSecondNumber.dRealPart;
  dImagineryPart -= c_rSecondNumber.dImagineryPart;
}

/*      Print Complex Numbers.      */

void Complex::PrintComplexNumber(void)
{
  cout << '('
       << dRealPart
       << ", "
       << dImagineryPart
       << ')';
}