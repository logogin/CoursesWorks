
#ifndef AnimalType_H
#define AnimalType_H
#include <iostream.h>

class AnimalType
{
	public:
		AnimalType(void)
		{}

		virtual void PrintAnimal(void) const=0
		{
			cout<<"Animal :"<<endl;
		} 
};

#endif AnimalType_H