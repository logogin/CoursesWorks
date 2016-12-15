#include <iostream.h>
#include <assert.h>
#include "Complex.h"
#include "CVector.h"

ComplexVector::ComplexVector(unsigned short iVectorSize):
VectorSize(iVectorSize)
{
	Vector=new Complex[VectorSize];
	assert(Vector!=NULL);
}

ComplexVector::ComplexVector(const ComplexVector &iCVector):
VectorSize(iCVector.VectorSize)
{
	Vector=new Complex[VectorSize];
	assert(Vector!=NULL);
	for (int i=0; i<VectorSize; i++)
		Vector[i]=iCVector.Vector[i];
}

ComplexVector::~ComplexVector()
{
	delete []Vector;
}

void ComplexVector::NewVector(unsigned short nVectorSize)
{
	VectorSize=nVectorSize;
	Vector=new Complex[nVectorSize];
	assert(Vector!=NULL);
}

ComplexVector &ComplexVector::operator=(const ComplexVector &operand)
{
	ComplexVector::ComplexVector(operand);
	for (int i=0; i<VectorSize; i++)
		Vector[i]=operand[i];
	return (*this);
}

const Complex &ComplexVector::operator[](const unsigned short index) const
{
	return Vector[index];
}

Complex &ComplexVector::operator[](const unsigned short index)
{
	return Vector[index];
}

const ComplexVector ComplexVector::operator+(const ComplexVector &operand) const
{
	assert(VectorSize==operand.VectorSize);
	ComplexVector Temp(*this);
	for (int i=0; i<VectorSize; i++)
		Temp[i]+=operand[i];
	return Temp;
}

const ComplexVector ComplexVector::operator-(const ComplexVector &operand) const
{
	assert(VectorSize==operand.VectorSize);
	ComplexVector Temp(*this);
	for (int i=0; i<VectorSize; i++)
		Temp[i]-=operand[i];
	return Temp;
}

const Complex ComplexVector::operator*(const ComplexVector &operand2) const
{
	assert(VectorSize==operand2.VectorSize);
	Complex Temp(0,0);
	ComplexVector operand1(*this);
	for (int i=0; i<VectorSize; i++)
		Temp+=(operand1[i]*operand2[i]);
	return Temp;
}

const ComplexVector ComplexVector::operator~() const
{
	ComplexVector Temp(*this);
	for (int i=0; i<VectorSize; i++)
		Temp[i]=~(Temp[i]);
	return Temp;
}

const Complex ComplexVector::operator^(const ComplexVector &operand) const
{
	return ((*this)*(~operand));
}

const ComplexVector ComplexVector::operator&(const ComplexVector &operand) const
{
	assert(VectorSize==operand.VectorSize);
	ComplexVector Temp(*this);
	for (int i=0; i<VectorSize; i++)
		Temp[i]*=operand[i];
	return Temp;
}

const ComplexVector ComplexVector::operator|(const ComplexVector &operand) const
{
	assert(VectorSize==operand.VectorSize);
	ComplexVector Temp(*this);
	for (int i=0 ;i<VectorSize; i++)
		Temp[i]/=operand[i];
	return Temp;
}

ComplexVector &ComplexVector::operator+=(const ComplexVector &operand)
{
	(*this)=(*this)+operand;
	return (*this);
}

ComplexVector &ComplexVector::operator-=(const ComplexVector &operand)
{
	(*this)=(*this)-operand;
	return (*this);
}

ComplexVector &ComplexVector::operator&=(const ComplexVector &operand)
{
	(*this)=(*this)&operand;
	return (*this);
}

ComplexVector &ComplexVector::operator|=(const ComplexVector &operand)
{
	(*this)=(*this)|operand;
	return (*this);
}

const bool ComplexVector::operator==(const ComplexVector &operand) const
{
	assert(VectorSize==operand.VectorSize);
	bool flag=true;
	for (int i=0; i<VectorSize; i++)
		if (Vector[i]!=operand[i])
			flag=false;
	return flag;
}

const bool ComplexVector::operator!=(const ComplexVector &operand) const
{
	assert(VectorSize==operand.VectorSize);
	bool flag=true;
	for (int i=0; i<VectorSize; i++)
		if (Vector[i]==operand[i])
			flag=false;
	return flag;
}

ostream &operator<<(ostream &out,const ComplexVector &oCVector)
{
	out<<"[";
	for (int i=0; i<oCVector.VectorSize-1; i++)
		out<<oCVector[i]<<",";
	out<<oCVector[oCVector.VectorSize-1]<<"]";
	return out;
}

istream &operator>>(istream &in,ComplexVector &iCVector)
{
	for (int i=0; i<iCVector.VectorSize; i++)
		in>>iCVector[i];
	return in;
}