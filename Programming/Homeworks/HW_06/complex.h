// 04.01.2001 Dmitry Zavyalov (c)
//
// Program " Expanded Class Complex "

#ifndef Complex_h
#define Complex_h

#include <iostream.h>

class Complex
{
private:
	float m_fReal;
	float m_fImaginary;

public:
//		Constructor
	Complex( float fR=0, float fI=0 ):
			m_fReal( fR ),
			m_fImaginary( fI ) {}
//		Copy Constructor
	Complex( const Complex &cNum ):
			m_fReal( cNum.m_fReal ),
			m_fImaginary( cNum.m_fImaginary ) {}

	Complex &operator  =( const Complex &cNum );
	Complex &operator +=( const Complex &cNum );
	Complex &operator -=( const Complex &cNum );
	Complex &operator *=( const Complex &cNum );
	Complex &operator /=( const Complex &cNum );
	Complex &operator ^=( const Complex &cNum );

	Complex operator +( const Complex &cNum ) const;
	Complex operator -( const Complex &cNum ) const;
	Complex operator *( const Complex &cNum ) const;
	Complex operator /( const Complex &cNum ) const;
	Complex operator ^( const Complex &cNum ) const;
	Complex operator ~( ) const;

	bool operator ==( const Complex &cNum ) const;
	bool operator !=( const Complex &cNum ) const;
//------------------------------------------------
	Complex& operator ()( float, float );
//	Complex& operator ()( float, char );

	Complex operator +( float [] );
	operator float *( ) const;
//------------------------------------------------
friend ostream& operator<< (ostream&, Complex&);
friend istream& operator>> (istream&, Complex&);

};

#endif
