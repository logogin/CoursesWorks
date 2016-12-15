
#ifndef Shark_H
#define Shark_H
#include "Fish.h"
#include "Carnivorous.h"

class Shark:public Fish,public Carnivorous
{
	public:
		Shark(void):Fish(),Carnivorous()
		{}

		virtual void PrintAnimal(void) const
		{
			AnimalType::PrintAnimal();
			cout<<"Shark ... "<<flush;
			Fish::PrintAnimal();
			Carnivorous::PrintAnimal();
		}
};

#endif Shark_H