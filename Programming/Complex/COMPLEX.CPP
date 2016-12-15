#include <iostream.h>
#include <assert.h>
#include <math.h>
#include "Complex.h"

Complex::Complex(const float iReal,const float iImaginary):
Real(iReal),Imaginary(iImaginary)
{
}

Complex::Complex(const Complex &icNumber):
Real(icNumber.Real),Imaginary(icNumber.Imaginary)
{
}

const Complex Complex::operator+(const Complex &operand) const
{
	return Complex(Real+operand.Real,Imaginary+operand.Imaginary);
}

const Complex Complex::operator-(const Complex &operand) const
{
	return Complex(Real-operand.Real,Imaginary-operand.Imaginary);
}

const Complex Complex::operator*(const Complex &operand) const
{
	return Complex(Real*operand.Real-Imaginary*operand.Imaginary,
		Imaginary*operand.Real+Real*operand.Imaginary);	
}

const Complex Complex::operator/(const Complex &operand) const
{
	float divisor=operand.Real*operand.Real+
		operand.Imaginary*operand.Imaginary;
	assert(divisor);
	return Complex((Real*operand.Real+Imaginary*operand.Imaginary)/divisor,
		(Imaginary*operand.Real-Real*operand.Imaginary)/divisor);
}

const Complex Complex::operator~() const
{
	return Complex(Real,-Imaginary);
}

const Complex Complex::operator^(const Complex &operand) const
{
	return ((*this)*(~operand));
}

Complex &Complex::operator=(const Complex &operand)
{
	Complex::Complex(operand);
	Real=operand.Real;
	Imaginary=operand.Imaginary;
	return (*this);
}

Complex &Complex::operator+=(const Complex &operand)
{
	(*this)=(*this)+operand;
	return (*this);
}

Complex &Complex::operator-=(const Complex &operand)
{
	(*this)=(*this)-operand;
	return (*this);
}

Complex &Complex::operator*=(const Complex &operand)
{
	(*this)=(*this)*operand;
	return (*this);
}

Complex &Complex::operator/=(const Complex &operand)
{
	(*this)=(*this)/operand;
	return (*this);
}

Complex &Complex::operator^=(const Complex &operand)
{
	(*this)=(*this)^operand;
	return (*this);
}

const bool Complex::operator==(const Complex &operand) const
{
	return (Real==operand.Real&&Imaginary==operand.Imaginary);
}

const bool Complex::operator!=(const Complex &operand) const
{
	return (Real!=operand.Real||Imaginary!=operand.Imaginary);
}

ostream &operator<<(ostream &out,const Complex &ocNumber)
{
	out<<ocNumber.Real<<
		(ocNumber.Imaginary>=0 ? "+i" : "-i")<<fabs(ocNumber.Imaginary);
	return out;
}

istream &operator>>(istream &in,Complex &icNumber)
{
	in>>icNumber.Real>>icNumber.Imaginary;
	return in;  
}

/*************HomeWork 06*****************/
Complex &Complex::operator()(const float rel,const float img)
{
	Real=rel;
	Imaginary=img;
	return (*this);
}

Complex &Complex::operator()(const float num,const char part)
{
	if (part=='R'||part=='r')
		Real=num;
	if (part=='I'||part=='i')
		Imaginary=num;
	return (*this);
}

const Complex Complex::operator+(const float operand[]) const
{
	Complex Temp(operand[0],operand[1]);
	return (*this+Temp);
}

const Complex operator+(const float LValue[],const Complex &RValue)
{
	Complex Temp(LValue[0],LValue[1]);
	return (Temp+RValue);
}

Complex::operator float *() const
{
	float *Temp;
	Temp=new float[2];
	Temp[0]=Real;
	Temp[1]=Imaginary;
	return Temp;
}