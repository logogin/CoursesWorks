
#ifndef Mouse_H
#define Mouse_H
#include "Mammals.h"
#include "Herbivorous.h"

class Mouse:public Mammals,public Herbivorous
{
	public:
		Mouse(void):Mammals(),Herbivorous()
		{}

		virtual void PrintAnimal(void) const
		{
			AnimalType::PrintAnimal();
			cout<<"Mouse ... "<<flush;
			Mammals::PrintAnimal();
			Herbivorous::PrintAnimal();
		}
};

#endif Mouse_H