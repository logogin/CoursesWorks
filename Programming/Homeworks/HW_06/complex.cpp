// 04.01.2001 Dmitry Zavyalov (c)
//
// Program " Expanded Class Complex "

#include "Complex.h"
#include <iostream.h>
#include <stdlib.h>

//		Oprator = Overloading
Complex &Complex::operator  =( const Complex &cNum )
{
	m_fReal = cNum.m_fReal;
	m_fImaginary = cNum.m_fImaginary;

	return( *this );
}

//		Oprator += Overloading
Complex &Complex::operator +=( const Complex &cNum )
{
	m_fReal += cNum.m_fReal;
	m_fImaginary += cNum.m_fImaginary;

	return( *this );
}

//		Oprator -= Overloading
Complex &Complex::operator -=( const Complex &cNum )
{
	m_fReal -= cNum.m_fReal;
	m_fImaginary -= cNum.m_fImaginary;

	return( *this );
}

//		Oprator *= Overloading
Complex &Complex::operator *=( const Complex &cNum )
{	// (ab-cd)+i(ad+bc)
	float Temp=0;
	Temp = m_fReal*cNum.m_fReal - m_fImaginary*cNum.m_fImaginary;
	m_fImaginary = m_fImaginary*cNum.m_fReal + m_fReal*cNum.m_fImaginary;
	m_fReal = Temp;
	return( *this );
}

//		Oprator /= Overloading
Complex &Complex::operator /=( const Complex &cNum )
{
	Complex cTemp = ~cNum;
	*this *= cTemp;
	m_fReal /= cNum.m_fReal*cNum.m_fReal + cNum.m_fImaginary*cNum.m_fImaginary;
	m_fImaginary /= cNum.m_fReal*cNum.m_fReal + cNum.m_fImaginary*cNum.m_fImaginary;
	return( *this );
}

//		Oprator + Overloading
Complex Complex::operator +( const Complex &cNum ) const
{
	Complex TempComp( *this );
	TempComp += cNum;
	return( TempComp );
}

//		Oprator - Overloading
Complex Complex::operator -( const Complex &cNum ) const
{
	Complex TempComp( *this );
	TempComp -= cNum;
	return( TempComp );
}

//		Oprator * Overloading
Complex Complex::operator *( const Complex &cNum ) const
{
	Complex TempComp( *this );
	TempComp *= cNum;
	return( TempComp );
}

//		Oprator / Overloading
Complex Complex::operator /( const Complex &cNum ) const
{
	Complex TempComp( *this );
	TempComp /= cNum;
	return( TempComp );
}

//		Oprator == Overloading
bool Complex::operator ==( const Complex &cNum ) const
{
	bool Ret=false;

	if( m_fReal==cNum.m_fReal && m_fImaginary==cNum.m_fImaginary ) Ret=true;

	return( Ret );
}

//		Oprator != Overloading
bool Complex::operator !=( const Complex &cNum ) const
{
	bool Ret=false;

	if( m_fReal!=cNum.m_fReal && m_fImaginary!=cNum.m_fImaginary ) Ret=true;

	return( Ret );
}

//		Print Complex Numbers
ostream& operator<<( ostream& Output, Complex &cNum )
{
	Output<<'('
		  <<cNum.m_fReal
		  <<", "
		  <<cNum.m_fImaginary
		  <<')';
	return Output;
}

//		Get Complex Number
istream& operator>>( istream& Input, Complex &cNum )
{
	Input>>cNum.m_fReal
		 >>cNum.m_fImaginary;
	return Input;
}

//		Oprator ~ Overloading
Complex Complex::operator ~( ) const
{
	Complex TempC( *this );
	TempC.m_fImaginary =- TempC.m_fImaginary;
	return( TempC );
}

//		Oprator ^= Overloading
Complex &Complex::operator ^=( const Complex &cNum )
{
	Complex TempC;
	TempC=~cNum;
	*this *= TempC;
	return( *this );
}

//		Oprator ^ Overloading
Complex Complex::operator ^( const Complex &cNum ) const
{
	Complex TempC( *this );
	TempC ^= cNum;
	return( TempC );
}
//------------------------------------------------------------

//		Oprator () Overloading HW_06
Complex& Complex::operator ()( float fNum, float cLetter )
{
	switch( cLetter )
	{
		case R: m_fReal = fNum; break;
		case r: m_fReal = fNum; break;
		case I: m_fImaginary = fNum; break;
		case i: m_fImaginary = fNum; break;
		default :
			{
				cout<< "Complex Number Input Error"
					<<endl;
				exit(1);
			}
	}
	return( *this );
}

//		Oprator + Overloading HW_06
/*/
Complex operator +(float cArr[], Complex &cNum )
{
  Complex TempC;

  TempC.m_fReal = cArr[0] + cNum.m_fReal;
  TempC.m_fImaginary = cArr[1] + cNum.m_fImaginary;

  return TempC;
}
/*/
//		Oprator + Overloading HW_06
Complex Complex::operator +( float cArr[] )
{
  Complex TempC( *this );

  TempC.m_fReal	+= cArr[0];
  TempC.m_fImaginary += cArr[1];

  return TempC;
}

//		Oprator * Overloading HW_06
Complex::operator float *( ) const
{
	float *TempC;
	TempC = new float[2];

	TempC[0] = m_fReal;
	TempC[1] = m_fImaginary;

	return ( TempC );
}
