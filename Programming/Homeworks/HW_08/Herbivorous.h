// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Herbivorous_h
#define Herbivorous_h
#include <iostream.h>
#include "AnimalEat.h"

class Herbivorous: public AnimalEat
{
	public:
		 virtual void PrintAnimalEat( ) const
		 {
				cout<<"  Herbivorous	"<<endl;
		 }
};
#endif
