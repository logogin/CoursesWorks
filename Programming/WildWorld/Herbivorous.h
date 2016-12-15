
#ifndef Herbivorous_H
#define Herbivorous_H
#include "AnimalEats.h"

class Herbivorous:public AnimalEats
{
	public:
		Herbivorous(void):AnimalEats()
		{}
			
		virtual void PrintAnimal(void) const
		{
			AnimalEats::PrintAnimal();
			cout<<" GRASS ... ;-)"<<endl;
		}
};

#endif Herbivorous_H