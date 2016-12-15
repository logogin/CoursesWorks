
#ifndef Carnivorous_H
#define Carnivorous_H
#include "AnimalEats.h"

class Carnivorous:public AnimalEats
{
	public:
		Carnivorous(void):AnimalEats()
		{}

		virtual void PrintAnimal(void) const
		{
			AnimalEats::PrintAnimal();
			cout<<" MEAT ... ;-( "<<endl;
		}
};
#endif Carnivorous_H