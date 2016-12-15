
#ifndef Lion_H
#define Lion_H
#include "Mammals.h"
#include "Carnivorous.h"

class Lion:public Mammals,public Carnivorous
{
	public:
		Lion(void):Mammals(),Carnivorous()
		{}

		virtual void PrintAnimal(void) const
		{
			AnimalType::PrintAnimal();
			cout<<"Lion ... "<<flush;
			Mammals::PrintAnimal();
			Carnivorous::PrintAnimal();
		}
};

#endif Lion_H