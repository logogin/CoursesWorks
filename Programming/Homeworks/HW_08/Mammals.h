// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Mammals_h
#define Mammals_h
#include <iostream.h>
#include "AnimalType.h"

class Mammals: public AnimalType
{
	public:
		 virtual void PrintAnimalName( ) const = 0;
		 virtual void PrintAnimalType( ) const
		 {
				cout<<"Mammals  ";
		 }
};
#endif
