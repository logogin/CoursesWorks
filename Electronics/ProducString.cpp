
#include <iostream.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include "Functions.h"
#include "ProductString.h"

ProductString::ProductString(const unsigned int iMinterm,const unsigned char iVarNumber)
:MintermNumber(1),VarNumber(iVarNumber)
{
	ProductString::ConvertNumber(iMinterm);
}

ProductString::ProductString(const ProductString &copy)
:VarNumber(copy.VarNumber),MintermNumber(copy.MintermNumber)
{
	void *ptr;
	pString=strdup(copy.pString);
	assert_pointer(pString);
	MintermArray=new unsigned int[MintermNumber];
	assert_pointer(MintermArray);
	ptr=memcpy(MintermArray,copy.MintermArray,sizeof(unsigned int)*copy.MintermNumber);
	assert_pointer(ptr);
}

ProductString::ProductString(const ProductString &operand1,const ProductString &operand2)
:VarNumber(operand1.VarNumber)
{
	(*this)=operand1+operand2;
}

ProductString::ProductString(void)
:VarNumber(0)
{
}

void ProductString::ConvertNumber(unsigned int cMinterm)
{
	MintermArray=new unsigned int(cMinterm);
	assert_pointer(MintermArray);
	ProductString::Convert2Binary();
}

void ProductString::Convert2Binary(void)
{
	char bit;
	unsigned int number=MintermArray[0];
	ProductString::pString=new_pointer(ProductString::pString,ProductString::VarNumber+1);
	pString[VarNumber]='\x0';
	for (int i=0; i<VarNumber; i++)
	{
		__asm
		{
				shr	number,1;
				jc	one;
				mov	bit,0x0;
				jmp	end;
		one:	mov bit,0x1;
		end:	nop;
		}

		bit+=0x30;
		pString[VarNumber-i-1]=bit;
	}
}

ProductString &ProductString::operator =(const ProductString &operand)
{
	void *ptr;
	VarNumber=operand.VarNumber;
	MintermNumber=operand.MintermNumber;
	pString=strdup(operand.pString);
	assert_pointer(pString);
	MintermArray=new_pointer(MintermArray,MintermNumber);
	ptr=memcpy(MintermArray,operand.MintermArray,sizeof(unsigned int)*MintermNumber);
	assert_pointer(ptr);
	return (*this);
}

const ProductString ProductString::operator +(const ProductString &operand) const
{
	bool different=false;
	void *ptr;
	ProductString Temp;
	Temp.VarNumber=VarNumber;
	Temp.pString=strdup(pString);
	assert_pointer(Temp.pString);
	Temp.MintermArray=new_pointer(Temp.MintermArray,MintermNumber+operand.MintermNumber);
	ptr=memcpy(Temp.MintermArray,MintermArray,sizeof(unsigned int)*MintermNumber);
	assert_pointer(ptr);
	Temp.MintermNumber=MintermNumber;
	ptr=memcpy((Temp.MintermArray+Temp.MintermNumber),
		(operand.MintermArray),
		sizeof(unsigned int)*operand.MintermNumber);
	assert_pointer(ptr);
	Temp.MintermNumber+=operand.MintermNumber;
	/******** Code Must Be Optimized !!! (Debug Version) ***********/
	for (unsigned int i=0; i<Temp.VarNumber; i++)
		if (Temp.pString[i]!=operand.pString[i])
		{
			if (!different)
				Temp.pString[i]='-';
			else
			{
				cerr<<"Minterms differs in more than one bit!!!"<<endl;
				exit(0);
			}
			different=true;
		}
	return Temp;
}

const bool ProductString::operator ^(const ProductString &operand) const
{
	unsigned char differents=0;
	for (int i=0; i<VarNumber; i++)

		if (pString[i]!=operand.pString[i])
			differents++;
	if (differents==1)
		return true;
	else
		return false;
}

const bool ProductString::operator ==(const ProductString &operand) const
{
	if (!strcmp(pString,operand.pString))
		return true;
	else
		return false;
}

void ProductString::PrintMinterms(ostream &out) const
{
	out<<MintermArray[0]<<flush;
	for (unsigned int i=1; i<MintermNumber; i++)
		out<<","<<MintermArray[i]<<flush;
}

unsigned int ProductString::GetMintermNumber(void) const
{
	return MintermNumber;
}

unsigned int ProductString::GetMintermNumber(const ProductString &operand) const
{
	return operand.GetMintermNumber();
}

unsigned int ProductString::Get1sNumber(void) const
{
	unsigned int count=0;
	for (unsigned int i=0; i<strlen(pString); i++)
		if (pString[i]=='1')
			count++;
	return count;
}

unsigned int ProductString::Get1sNumber(const ProductString &element) const
{
	return element.Get1sNumber();
}

unsigned int ProductString::GetMinterm(const unsigned int index) const
{
	return MintermArray[index];
}

ProductString::~ProductString(void)
{
	delete []pString;
	delete []MintermArray;
}

ostream &operator<<(ostream &out,const ProductString &operand)
{
	out<<operand.pString<<flush;
	return out;
}