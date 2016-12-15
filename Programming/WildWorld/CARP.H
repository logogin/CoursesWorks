
#ifndef Carp_H
#define Carp_H
#include "Fish.h"
#include "Herbivorous.h"

class Carp:public Fish,public Herbivorous
{
	public:
		Carp(void):Fish(),Herbivorous()
		{}

		virtual void PrintAnimal(void) const
		{
			AnimalType::PrintAnimal();
			cout<<"Carp ... "<<flush;
			Fish::PrintAnimal();
			Herbivorous::PrintAnimal();
		}
};

#endif Carp_H