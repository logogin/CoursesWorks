// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Carnivorous_h
#define Carnivorous_h
#include <iostream.h>
#include "AnimalEat.h"

class Carnivorous: public AnimalEat
{
	public:
		 virtual void PrintAnimalEat( ) const
		 {
				cout<<"  Carnivorous  "<<endl;
		 }
};
#endif
