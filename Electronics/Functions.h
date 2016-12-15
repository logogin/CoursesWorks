
#ifndef Functions_H
#define Functions_H

#include <iostream.h>
#include <stdlib.h>
#include "ProductString.h"

template <typename type>
type *new_pointer(type *pointer,const unsigned int number)
{
	pointer=new type[number];
	if (pointer==NULL)
	{
		cerr<<"Allocation filed!!!(new_pointer)"<<endl;
		exit(1);
	}
	return pointer;
}

template <typename type>
type *realloc_pointer(type *pointer,const unsigned int number)
{
	pointer=(type *)realloc(reinterpret_cast<void *>(pointer),
		sizeof(type)*number);
	if (pointer==NULL)
	{
		cerr<<"Allocation filed!!!(realloc_pointer)"<<endl;
		exit(1);
	}
	return pointer;
}

template <typename type>
void assert_pointer(const type *pointer)
{
	if (pointer==NULL)
	{
		cerr<<"Assertion filed at section "<<&pointer<<endl;
		exit(1);
	}
}

template <typename type>
int in_vector(const type element, const type *pointer,const unsigned int size)
{
	bool flag=false;
	unsigned int i=0;
	while(!flag&&i<size)
		if (pointer[i]==element)
			flag=true;
		else
			i++;
	if (flag)
		return i;
	else
		return -1;
}

#endif Functions_H