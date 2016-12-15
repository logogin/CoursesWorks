
#ifndef AnimalEats_H
#define AnimalEats_H
#include <iostream.h>

class AnimalEats
{
	public:
		AnimalEats(void)
		{}

		virtual void PrintAnimal(void) const=0
		{
			cout<<"... and They prefere to eat ..."<<flush;
		}

};

#endif AnimalEats_H