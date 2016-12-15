// 17.12.2000 Dmitry Zavyalov (c)
//
// Program " Class Complex "

#include "c_vector.h"

#include <iostream.h>
#include <stdlib.h>

//		Constructor
ComplexVector::ComplexVector(unsigned short usVSize ) : m_pComplex(NULL)
{
	GetVector(usVSize);
}

//		Build Vector with size "usVSize"
ComplexVector::GetVector(unsigned short usVSize)
{
	m_usVectorSize = usVSize;
	if ( m_usVectorSize != 0 ) m_pComplex = new Complex[usVSize];
}

//		Copy Constructor
ComplexVector::ComplexVector(const ComplexVector &cVec)
				:m_usVectorSize ( cVec.m_usVectorSize )
{
//	if ( m_pComplex != NULL ) delete m_pComplex;
	m_pComplex = new Complex[m_usVectorSize];
	for( int counter=0; counter<m_usVectorSize; counter++ )
		m_pComplex[counter] = cVec[counter];
}

//		Destructor
ComplexVector::~ComplexVector( )
{
	delete[]m_pComplex;
}

//		Overloading = Operator
ComplexVector& ComplexVector::operator =( const ComplexVector &cVec )
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usVectorSize; counter++ )
		m_pComplex[counter] = cVec.m_pComplex[counter];
	return( *this );
}

//		Overloading << Operator
ostream& operator <<(ostream& Output, ComplexVector &cVec)
{
	Output<<"["
		<<cVec[0];
	for( int counter=1; counter<cVec.m_usVectorSize; counter++ )
		Output<<", " <<cVec[counter];
	Output<<"]";
	return Output;
}

//		Overloading >> Operator
istream& operator >>(istream& Input, ComplexVector &cVec)
{
	for( int counter=0; counter<cVec.m_usVectorSize; counter++ )
		Input>>cVec[counter];
	return Input;
}

//		Overloading [] Operator
Complex& ComplexVector::operator []( const unsigned short usSubScript )
{
	return( m_pComplex[usSubScript] );
}

//		Overloading []const Operator
const Complex& ComplexVector::operator []( const unsigned short usSubScript ) const
{
	return( m_pComplex[usSubScript] );
}


//		Overloading += Operator
ComplexVector& ComplexVector::operator +=( const ComplexVector &cVec )
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usVectorSize; counter++ )
		m_pComplex[counter]+=cVec.m_pComplex[counter];
	return( *this );
}

//		Overloading -= Operator
ComplexVector& ComplexVector::operator -=( const ComplexVector &cVec )
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usVectorSize; counter++ )
	m_pComplex[counter]-=cVec.m_pComplex[counter];
	return( *this );
}

//		Overloading &= Operator
ComplexVector& ComplexVector::operator &=( const ComplexVector &cVec )
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usVectorSize; counter++ )
	m_pComplex[counter]*=cVec.m_pComplex[counter];
	return( *this );
}

//		Overloading |= Operator
ComplexVector& ComplexVector::operator |=( const ComplexVector &cVec )
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( *this );
	}
	for( int counter=0; counter<m_usVectorSize; counter++ )
	m_pComplex[counter]/=cVec.m_pComplex[counter];
	return( *this );
}

//		Overloading == Operator
bool ComplexVector::operator ==( const ComplexVector &cVec ) const
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( false );
	}
	bool Ret=true;
	for( int counter=0; counter<m_usVectorSize; counter++ )
		if( m_pComplex[counter]!=cVec.m_pComplex[counter] ) Ret=false;
	return( Ret );
}

//		Overloading != Operator
bool ComplexVector::operator !=( const ComplexVector &cVec ) const
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( true );
	}
	bool Ret=true;
	for( int counter=0; counter<m_usVectorSize; counter++ )
		if( m_pComplex[counter]==cVec.m_pComplex[counter] ) Ret=false;
	return( Ret );
}

//		Overloading + Operator
ComplexVector ComplexVector::operator +( const ComplexVector &cVec ) const
{
	ComplexVector Temp_cVec( *this );
	Temp_cVec += cVec;
	return( Temp_cVec );
}

//		Overloading - Operator
ComplexVector ComplexVector::operator -( const ComplexVector &cVec ) const
{
	ComplexVector Temp_cVec( *this );
	Temp_cVec -= cVec;
	return( Temp_cVec );
}

//		Overloading & Operator
ComplexVector ComplexVector::operator &( const ComplexVector &cVec ) const
{
	ComplexVector Temp_cVec( *this );
	Temp_cVec &= cVec;
	return( Temp_cVec );
}

//		Overloading | Operator
ComplexVector ComplexVector::operator |( const ComplexVector &cVec ) const
{
	ComplexVector Temp_cVec( *this );
	Temp_cVec |= cVec;
	return( Temp_cVec );
}

//		Overloading ^ Operator
Complex ComplexVector::operator ^( const ComplexVector &cVec ) const
{
	Complex cTemp;
	cTemp = *this * ~cVec;
	return( cTemp );
}

//		Overloading * Operator
Complex ComplexVector::operator *( const ComplexVector &cVec ) const
{
	if( m_usVectorSize != cVec.m_usVectorSize )
	{
		cout<<"\nError In Vector Size...\n";
		return( 0 );
	}
	Complex TempC;
	for( int counter=0; counter<cVec.m_usVectorSize; counter++ )
		TempC += m_pComplex[counter] * cVec.m_pComplex[counter];
	return( TempC );
}

//		Overloading ~ Operator
ComplexVector ComplexVector::operator ~( ) const
{
	ComplexVector Temp_cVec( *this );
	for( int counter=0; counter<Temp_cVec.m_usVectorSize; counter++ )
		Temp_cVec.m_pComplex[counter] = ~Temp_cVec.m_pComplex[counter];
	return( Temp_cVec );
}
