#include <iostream.h>
#include <math.h>
#include "Rational.h"

/*        Constructor - Initiation of Parameters.      */

Rational::Rational(int iNum,
                   int iDen)
{
  iNumerator = iNum;
  iDenominator = iDen;
}

/*     Addition Between 2 Rational Numbers,    */
/*                and Reduction.               */
/*      The Output Saved in AdditionResult.    */

Rational Rational::Addition(const Rational &SecondNumber)
{
  Rational AdditionResult;

  AdditionResult.iNumerator = SecondNumber.iNumerator * iDenominator + SecondNumber.iDenominator * iNumerator;
  AdditionResult.iDenominator = SecondNumber.iDenominator * iDenominator;
  AdditionResult.Reduction();

  return AdditionResult;
}

/*   Subtruction Between 2 Rational Numbers,   */
/*                and Reduction.               */
/*     The Output Saved in SubtructResult.     */

Rational Rational::Subtraction(const Rational &SecondNumber)
{
  Rational SubtructResult;

  SubtructResult.iNumerator = SecondNumber.iDenominator * iNumerator - SecondNumber.iNumerator * iDenominator;
  SubtructResult.iDenominator = SecondNumber.iDenominator * iDenominator;
  SubtructResult.Reduction();

  return SubtructResult;
}

/*  Multiplication Between 2 Rational Numbers, */
/*                and Reduction.               */
/*   The Output Saved in MultiplicatinResult.  */

Rational Rational::Multiplication(const Rational &SecondNumber)
{
  Rational MultiplicationResult;

  MultiplicationResult.iNumerator = iNumerator * SecondNumber.iNumerator;
  ;
  MultiplicationResult.iDenominator = SecondNumber.iDenominator *
                                      iDenominator;
  MultiplicationResult.Reduction();

  return MultiplicationResult;
}

/*     Division Between 2 Rational Numbers,    */
/*                and Reduction.               */
/*      The Output Saved in DivisionResult.    */

Rational Rational::Division(const Rational &SecondNumber)
{
  Rational DivisionResult;

  DivisionResult.iNumerator = iNumerator * SecondNumber.iDenominator;
  DivisionResult.iDenominator = SecondNumber.iNumerator * iDenominator;
  DivisionResult.Reduction();

  return DivisionResult;
}

/*    Printing Rational Numbers as Rational.    */

void Rational::PrintRational(void)
{
  if (iDenominator == 0)
  {
    cout << "\nDivide By Zero\n";
  }
  else
  {
    if (iNumerator == 0)
    {
      cout << 0
           << endl;
    }
    else
    {
      cout << iNumerator
           << "/"
           << iDenominator;
    }
  }
}

/*    Printing Rational Numbers as Real Number.    */

void Rational::PrintRationalAsFloat(void)
{
  cout << (double)iNumerator / (double)iDenominator;
}

/*      Reduce Rational Numbers.      */

void Rational::Reduction(void)
{
  int iSmallest = abs(iNumerator) < abs(iDenominator) ? abs(iNumerator) : abs(iDenominator);
  int iHalfSmallest;
  int iGreatestDividor = 1;

  iHalfSmallest = iSmallest / 2;

  if ((iNumerator % iSmallest == 0) &&
      (iDenominator % iSmallest == 0))
  {
    iGreatestDividor = iSmallest;
  }
  else
  {
    for (int iCounter = 2; iCounter <= iHalfSmallest; iCounter++)
    {
      if ((iNumerator % iCounter == 0) &&
          (iDenominator % iCounter == 0))
      {
        iGreatestDividor = iCounter;
      }
    }
  }

  if (iGreatestDividor != 1)
  {
    iNumerator /= iGreatestDividor;
    iDenominator /= iGreatestDividor;
  }
}
