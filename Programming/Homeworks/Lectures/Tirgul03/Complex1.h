/*   Prototype of the Complex Class.   */

#ifndef Tar3Ex1_Complex
#define Tar3Ex1_Complex

class Complex
{
public:
  Complex(double dReal = 0.0,
          double dImaginery = 0.0);
  void SetComplexNumber(double dReal,
                        double dImaginery);
  void ComplexAddition(const Complex &c_rSecondNumber);
  void ComplexSubtraction(const Complex &c_rSecondNumber);
  void PrintComplexNumber(void);

private:
  double dRealPart;
  double dImagineryPart;
};

#endif
