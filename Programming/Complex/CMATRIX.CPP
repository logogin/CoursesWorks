#include <iostream.h>
#include <assert.h>
#include "Complex.h"
#include "CVector.h"
#include "CMatrix.h"


ComplexMatrix::ComplexMatrix(const unsigned short iColumnSize,
							 const unsigned short iRowSize):
ColumnSize(iColumnSize),
RowSize(iRowSize)
{
	Matrix=new ComplexVector[RowSize];
	assert(Matrix!=NULL);
	for (int i=0; i<RowSize; i++)
		Matrix[i].NewVector(ColumnSize);
}

ComplexMatrix::ComplexMatrix(const ComplexMatrix &iCMatrix):
ColumnSize(iCMatrix.ColumnSize),
RowSize(iCMatrix.RowSize)
{
	Matrix=new ComplexVector[RowSize];
	assert(Matrix!=NULL);
	for (int i=0; i<RowSize; i++)
	{
		Matrix[i].NewVector(ColumnSize);
		Matrix[i]=iCMatrix.Matrix[i];
	}
}

ComplexMatrix::~ComplexMatrix()
{
	delete []Matrix;
}

const ComplexVector &ComplexMatrix::operator[](const unsigned short Index) const
{
	return Matrix[Index]; 
}

ComplexVector &ComplexMatrix::operator[](const unsigned short Index)
{
	return Matrix[Index];
}

ComplexMatrix &ComplexMatrix::operator=(const ComplexMatrix &operand)
{
	ComplexMatrix::ComplexMatrix(operand);
	return (*this);
}

const ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix &operand) const
{
	assert(RowSize==operand.RowSize);
	ComplexMatrix Temp(*this);
	for (int i=0; i<RowSize; i++)
		Temp[i]+=operand[i];
	return Temp;
}

const ComplexMatrix ComplexMatrix::operator-(const ComplexMatrix &operand) const
{
	assert(RowSize==operand.RowSize);
	ComplexMatrix Temp(*this);
	for (int i=0; i<RowSize; i++)
		Temp[i]-=operand[i];
	return Temp;
}

const ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix &operand) const
{
	assert(RowSize==operand.ColumnSize);
	ComplexMatrix Temp(ColumnSize,operand.RowSize);
	for (int i=0; i<ColumnSize; i++)
		for (int j=0; j<operand.RowSize; j++)
		{
			Complex cNum(0,0);
			for (int k=0; k<RowSize; k++)
				cNum+=Matrix[k][i]*operand[j][k];
			Temp[j][i]=cNum;
		}
	return Temp;
}

const ComplexMatrix ComplexMatrix::operator&(const ComplexMatrix &operand) const
{
	assert(RowSize==operand.RowSize);
	ComplexMatrix Temp(*this);
	for (int i=0; i<RowSize; i++)
		Temp[i]&=operand[i];
	return Temp;
}

const ComplexMatrix ComplexMatrix::operator|(const ComplexMatrix &operand) const
{
	assert(RowSize==operand.RowSize);
	ComplexMatrix Temp(*this);
	for (int i=0; i<RowSize; i++)
		Temp[i]|=operand[i];
	return Temp;
}

const ComplexMatrix ComplexMatrix::operator~() const
{
	ComplexMatrix Temp(*this);
 	for (int i=0; i<RowSize; i++)
		Temp[i]=~Temp[i];
	return Temp;	
}

const ComplexMatrix ComplexMatrix::operator!() const
{
	ComplexMatrix Temp(RowSize,ColumnSize);
	for (int i=0; i<RowSize; i++)
		for (int j=0 ;j<ColumnSize; j++)
			Temp[j][i]=Matrix[i][j];
	return Temp;
}

const ComplexMatrix ComplexMatrix::operator^(const ComplexMatrix &operand) const
{
	return ((*this)*(!(~operand)));
}

ComplexMatrix &ComplexMatrix::operator+=(const ComplexMatrix &operand)
{
	(*this)=(*this)+operand;
	return (*this);
}

ComplexMatrix &ComplexMatrix::operator-=(const ComplexMatrix &operand)
{
	(*this)=(*this)-operand;
	return (*this);
}

ComplexMatrix &ComplexMatrix::operator*=(const ComplexMatrix &operand)
{
	(*this)=(*this)*operand;
	return (*this);
}

ComplexMatrix &ComplexMatrix::operator&=(const ComplexMatrix &operand)
{
	(*this)=(*this)&operand;
	return (*this);
}

ComplexMatrix &ComplexMatrix::operator|=(const ComplexMatrix &operand)
{
	(*this)=(*this)|operand;
	return (*this);
}

ComplexMatrix &ComplexMatrix::operator^=(const ComplexMatrix &operand)
{
	(*this)=(*this)^operand;
	return (*this);
}

const bool ComplexMatrix::operator==(const ComplexMatrix &operand) const
{
	assert(RowSize==operand.RowSize);
	bool flag=true;
	ComplexMatrix Temp(*this);
	for (int i=0; i<RowSize; i++)
		if (Temp[i]!=operand[i])
			flag=false;
	return flag;
}

const bool ComplexMatrix::operator!=(const ComplexMatrix &operand) const
{
	assert(RowSize==operand.RowSize);
	bool flag=true;
	ComplexMatrix Temp(*this);
	for (int i=0; i<RowSize; i++)
		if (Temp[i]==operand[i])
			flag=false;
	return flag;
}

ostream &operator<<(ostream &out,const ComplexMatrix &oCMatrix)
{
	for (int i=0; i<oCMatrix.RowSize; i++)
		out<<oCMatrix[i]<<endl;
	return out;
}

istream &operator>>(istream &in,ComplexMatrix &iCMatrix)
{
	for (int i=0; i<iCMatrix.RowSize; i++)
		in>>iCMatrix[i];
	return in;
}