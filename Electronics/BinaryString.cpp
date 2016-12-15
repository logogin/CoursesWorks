
#include <string.h>
#include "Functions.h"
#include "BinaryString.h"

BinaryString::BinaryString(const unsigned int number,const unsigned int size)
:Number(number),Size(size)
{
	Convert();
}

void BinaryString::Convert(void)
{
	char bit; 
	unsigned int number=Number;
	bString=new_pointer(bString,Size+1);
	for (unsigned int i=0; i<Size; i++)
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
		bString[Size-i-1]=bit;
	}
	bString[Size]='\x0';
}

void BinaryString::SetNewString(const unsigned int number)
{
	delete []bString;
	Convert();
}

unsigned int BinaryString::Get1sNumber(void) const
{
	unsigned int count=0;
	for (unsigned int i=0; i<Size; i++)
		if (bString[i])
			count++;
	return count;
}

char *BinaryString::GetString(void) const
{
	char *temp=NULL;
	void *ptr;
	temp=new_pointer(temp,Size+1);
	ptr=memcpy(temp,bString,(Size+1)*sizeof(char));
	assert_pointer(ptr);
	return temp;
}

unsigned int BinaryString::GetSize(void) const
{
	return Size;
}

BinaryString::~BinaryString(void)
{
	delete []bString;
}