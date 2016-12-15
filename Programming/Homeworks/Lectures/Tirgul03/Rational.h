/*   Prototype of the Rational Class.   */

#ifndef Tar3Ex2_Rational
#define Tar3Ex2_Rational

class Rational
{
public:
  Rational(int iNum = 0, int iDen = 1);
  Rational Addition(const Rational &SecondNumber);
  Rational Subtraction(const Rational &SecondNumber);
  Rational Multiplication(const Rational &SecondNumber);
  Rational Division(const Rational &SecondNumber);
  void PrintRational(void);
  void PrintRationalAsFloat(void);

private:
  int iNumerator;
  int iDenominator;
  void Reduction(void);
};

#endif