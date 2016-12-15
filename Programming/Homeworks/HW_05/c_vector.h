// 17.12.2000 Dmitry Zavyalov (c)
//
// Program " Class Complex "

#ifndef ComplexVector_h
#define ComplexVector_h

#include "Complex.h"

class ComplexVector
{
friend ostream& operator <<( ostream&, ComplexVector& );
friend istream& operator >>( istream&, ComplexVector& );

private:
	unsigned short m_usVectorSize;
	Complex *m_pComplex;

public:
	ComplexVector( unsigned short usVSize=0 );
	GetVector(unsigned short usVSize);
	ComplexVector( const ComplexVector &cVec );
	~ComplexVector( );

	ComplexVector& operator  =( const ComplexVector &cVec );
	ComplexVector& operator +=( const ComplexVector &cVec );
	ComplexVector& operator -=( const ComplexVector &cVec );
	ComplexVector& operator &=( const ComplexVector &cVec );
	ComplexVector& operator |=( const ComplexVector &cVec );

	ComplexVector operator +( const ComplexVector &cVec ) const;
	ComplexVector operator -( const ComplexVector &cVec ) const;
	ComplexVector operator &( const ComplexVector &cVec ) const;
	ComplexVector operator |( const ComplexVector &cVec ) const;

	bool operator ==( const ComplexVector &cVec ) const;
	bool operator !=( const ComplexVector &cVec ) const;

	Complex& operator []( const unsigned short usSubScript );
	const Complex& operator []( const unsigned short usSubScript ) const;

	Complex operator ^( const ComplexVector &cVec ) const;
	Complex operator *( const ComplexVector &cVec ) const;
	ComplexVector operator ~( ) const;
};
#endif
