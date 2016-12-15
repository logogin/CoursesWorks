// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Carp_h
#define Carp_h
#include <iostream.h>
#include "Fish.h"
#include "Herbivorous.h"

class Carp: public Fish, public Herbivorous
{
	public:
		 virtual void PrintAnimalName( ) const
		 {
				Fish::PrintAnimalType( );
				cout<<"  Carps  ";
				Herbivorous::PrintAnimalEat( );
		 }
};
#endif
