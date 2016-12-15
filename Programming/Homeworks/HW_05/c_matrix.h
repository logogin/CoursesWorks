// 17.12.2000 Dmitry Zavyalov (c)
//
// Program " Class Complex "

#ifndef ComplexMatrix_h
#define ComplexMatrix_h

#include "complex.h"
#include "c_vector.h"
#include <iostream.h>

class ComplexMatrix
{
friend ostream& operator <<( ostream&, const ComplexMatrix& );
friend istream& operator >>( istream&, ComplexMatrix& );

private:
	unsigned short m_usColumnSize;
	unsigned short m_usRowSize;
	ComplexVector *m_pComplexVector;

public:
	 ComplexMatrix( unsigned short usVNum=0, unsigned short usVSize=0);
	 ComplexMatrix( const ComplexMatrix &cMatr );
	~ComplexMatrix( );

	ComplexVector& operator []( const unsigned short usSubScript );
	const ComplexVector& operator []( const unsigned short usSubScript ) const;

	ComplexMatrix& operator +=( const ComplexMatrix& cMatr );
	ComplexMatrix& operator -=( const ComplexMatrix& cMatr );
	ComplexMatrix& operator &=( const ComplexMatrix& cMatr );
	ComplexMatrix& operator |=( const ComplexMatrix& cMatr );
	ComplexMatrix& operator  =( const ComplexMatrix &cMatr );

	ComplexMatrix operator +( const ComplexMatrix &cMatr ) const;
	ComplexMatrix operator -( const ComplexMatrix &cMatr ) const;
	ComplexMatrix operator &( const ComplexMatrix &cMatr ) const;
	ComplexMatrix operator |( const ComplexMatrix &cMatr ) const;

	ComplexMatrix operator !( ) const;
	ComplexMatrix operator *( ComplexMatrix &cMatr ) const;
	ComplexMatrix operator ^( const ComplexMatrix &cMatr ) const;
};

#endif
