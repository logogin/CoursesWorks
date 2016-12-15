
#ifndef Fish_H
#define Fish_H
#include "AnimalType.h"

class Fish:public AnimalType
{
	public:
		Fish(void):AnimalType()
		{}

		virtual void PrintAnimal(void) const
		{
			cout<<"They are Fishes ... "<<endl;
		}
};

#endif Fish_H