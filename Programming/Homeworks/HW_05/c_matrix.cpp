// 17.12.2000 Dmitry Zavyalov (c)
//
// Program " Class Complex "

#include "complex.h"
#include "c_vector.h"
#include "c_matrix.h"
#include <iostream.h>
#include <malloc.h>

//		Constructor
ComplexMatrix::ComplexMatrix( unsigned short usVNum, unsigned short usVSize )
{
	m_usColumnSize = usVSize;		//	Vector Size
	m_usRowSize    = usVNum;		//	Number Of Vectors
	m_pComplexVector = new ComplexVector[m_usRowSize];
	for( int counter=0; counter<m_usRowSize; counter++ )
		m_pComplexVector[counter].GetVector( m_usColumnSize );
}

//		Copy Constructor
ComplexMatrix::ComplexMatrix( const ComplexMatrix &cMatr )
			:m_usColumnSize( cMatr.m_usColumnSize ),
			 m_usRowSize( cMatr.m_usRowSize)
{
	m_pComplexVector = new ComplexVector[m_usRowSize];
	for( int counter=0; counter<m_usRowSize; counter++ )
	{
		m_pComplexVector[counter].GetVector( m_usColumnSize );
		m_pComplexVector[counter] = cMatr.m_pComplexVector[counter];
	}
}

//		Destructor
ComplexMatrix::~ComplexMatrix( )
{
	delete[]m_pComplexVector;
}


//		Overloading << Operator
ostream& operator <<( ostream &Output, const ComplexMatrix &cMatr )
{
	for( int counter=0; counter<cMatr.m_usRowSize; counter++ )
		cout<<((ComplexMatrix&)cMatr)[counter] <<endl;
	return( Output );
}

//		Overloading >> Operator
istream& operator >>( istream &Input, ComplexMatrix &cMatr )
{
	for( int counter=0; counter<cMatr.m_usRowSize; counter++ )
		Input>>cMatr[counter];
	return( Input );
}

//		Overloading [] Operator
ComplexVector& ComplexMatrix::operator []( const unsigned short usSubScript )
{
	return( m_pComplexVector[usSubScript] );
}

//		Overloading [] Operator
const ComplexVector& ComplexMatrix::operator []( const unsigned short usSubScript ) const
{
	return( m_pComplexVector[usSubScript] );
}

//		Overloading += Operator
ComplexMatrix& ComplexMatrix::operator +=( const ComplexMatrix& cMatr )
{
	if( m_usRowSize != cMatr.m_usRowSize || m_usColumnSize!=cMatr.m_usColumnSize)
	{
		cout<<"\nError In Matrix Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usRowSize; counter++ )
		m_pComplexVector[counter] += cMatr.m_pComplexVector[counter];
	return( *this );
}

//		Overloading -= Operator
ComplexMatrix& ComplexMatrix::operator -=( const ComplexMatrix& cMatr )
{
	if( m_usRowSize != cMatr.m_usRowSize || m_usColumnSize!=cMatr.m_usColumnSize)
	{
		cout<<"\nError In Matrix Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usRowSize; counter++ )
		m_pComplexVector[counter] -= cMatr.m_pComplexVector[counter];
	return( *this );
}

//		Overloading &= Operator
ComplexMatrix& ComplexMatrix::operator &=( const ComplexMatrix& cMatr )
{
	if( m_usRowSize != cMatr.m_usRowSize || m_usColumnSize!=cMatr.m_usColumnSize)
	{
		cout<<"\nError In Matrix Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usRowSize; counter++ )
		m_pComplexVector[counter] &= cMatr.m_pComplexVector[counter];
	return( *this );
}

//		Overloading |= Operator
ComplexMatrix& ComplexMatrix::operator |=( const ComplexMatrix& cMatr )
{
	if( m_usRowSize != cMatr.m_usRowSize || m_usColumnSize!=cMatr.m_usColumnSize)
	{
		cout<<"\nError In Matrix Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usRowSize; counter++ )
		m_pComplexVector[counter] |= cMatr.m_pComplexVector[counter];
	return( *this );
}


//		Overloading + Operator
ComplexMatrix ComplexMatrix::operator +(const ComplexMatrix &cMatr ) const
{
	ComplexMatrix Temp_cMatr( *this );
	Temp_cMatr += cMatr;
	return( Temp_cMatr );
}

//		Overloading -Operator
ComplexMatrix ComplexMatrix::operator -(const ComplexMatrix &cMatr ) const
{
	ComplexMatrix Temp_cMatr( *this );
	Temp_cMatr -= cMatr;
	return( Temp_cMatr );
}

//		Overloading & Operator
ComplexMatrix ComplexMatrix::operator &(const ComplexMatrix &cMatr ) const
{
	ComplexMatrix Temp_cMatr( *this );
	Temp_cMatr &= cMatr;
	return( Temp_cMatr );
}

//		Overloading | Operator
ComplexMatrix ComplexMatrix::operator |(const ComplexMatrix &cMatr ) const
{
	ComplexMatrix Temp_cMatr( *this );
	Temp_cMatr |= cMatr;
	return( Temp_cMatr );
}

//		Overloading ^ Operator
ComplexMatrix ComplexMatrix::operator ^( const ComplexMatrix &cMatr ) const
{
	ComplexMatrix Temp_cMatr( *this );
//	assert(m_usColumnSize == ComMat.m_usColumnSize);
	if( m_usRowSize != cMatr.m_usRowSize || m_usColumnSize!=cMatr.m_usColumnSize)
	{
		cout<<"\nError In Matrix Size...\n";
		return( *this );
	}
	for(int i = 0; i < m_usRowSize; i++)
		Temp_cMatr.m_pComplexVector[i] =~cMatr.m_pComplexVector[i];
	return ( (*this) * (!Temp_cMatr) );
}

//		Overloading ! Operator
ComplexMatrix ComplexMatrix::operator !( ) const
{
	ComplexMatrix Temp_cMatr( *this );
	for( int counter1=0; counter1<m_usRowSize; counter1++ )
		for( int counter2=0; counter2<m_usColumnSize; counter2++ )
			Temp_cMatr.m_pComplexVector[counter1][counter2] = m_pComplexVector[counter2][counter1];
	return( Temp_cMatr );
}

//		Overloading * Operator
ComplexMatrix ComplexMatrix :: operator* ( ComplexMatrix &cMatr ) const
{
  ComplexMatrix Temp_cMatr( *this );
//  assert(m_usRowSize == ComMat.m_usColumnSize);
	if( m_usRowSize != cMatr.m_usRowSize || m_usColumnSize!=cMatr.m_usColumnSize)
	{
		cout<<"\nError In Matrix Size...\n";
		return( *this );
	}
	for(int i = 0; i < m_usRowSize; i++)
		for(int j = 0; j < m_usRowSize; j++)
			for(int k = 0; k < cMatr.m_usRowSize; k++ )
	Temp_cMatr.m_pComplexVector[i][j] += m_pComplexVector[i][k] * cMatr.m_pComplexVector[k][j];
   return Temp_cMatr;
}

//		Overloading = Operator
ComplexMatrix& ComplexMatrix::operator =( const ComplexMatrix &cMatr )
{
//	assert(m_usColumnSize == ComMat.m_usColumnSize);
	if( m_usRowSize != cMatr.m_usRowSize || m_usColumnSize!=cMatr.m_usColumnSize)
	{
		cout<<"\nError In Matrix Size...\n";
		return( *this );
	}
	for(int counter=0; counter<m_usRowSize; counter++)
		m_pComplexVector[counter] = cMatr.m_pComplexVector[counter];
	return ( *this );
}
