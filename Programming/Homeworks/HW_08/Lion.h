// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Lion_h
#define Lion_h
#include <iostream.h>
#include "Mammals.h"
#include "Carnivorous.h"

class Lion: public Mammals, public Carnivorous
{
	public:
		 virtual void PrintAnimalName( ) const
		 {
				Mammals::PrintAnimalType( );
				cout<<"  Lions  ";
				Carnivorous::PrintAnimalEat( );
		 }
};
#endif
