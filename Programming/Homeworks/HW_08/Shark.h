// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Shark_h
#define Shark_h
#include <iostream.h>
#include "Fish.h"
#include "Carnivorous.h"

class Shark: public Fish, public Carnivorous
{
	public:
		 virtual void PrintAnimalName( ) const
		 {
				Fish::PrintAnimalType( );
				cout<<"  Sharks ";
				Carnivorous::PrintAnimalEat( );
		 }
};
#endif
