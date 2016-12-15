// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Fish_h
#define Fish_h
#include <iostream.h>
#include "AnimalType.h"

class Fish: public AnimalType
{
	public:
		 virtual void PrintAnimalName( ) const = 0;
		 virtual void PrintAnimalType( ) const
		 {
				cout<<"Fishes   ";
		 }
};
#endif
