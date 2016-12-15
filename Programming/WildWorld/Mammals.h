
#ifndef Mammals_H
#define Mammals_H
#include "AnimalType.h"

class Mammals:public AnimalType
{
	public:
		Mammals(void):AnimalType()
		{}

		virtual void PrintAnimal(void) const
		{
			cout<<"They are Mammals ... "<<endl;
		}

};

#endif Mammals_H