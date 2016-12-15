// 17.12.2000 Dmitry Zavyalov (c)
//
// Program " Class Complex "

#include "Complex.h"
#include <iostream.h>

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
