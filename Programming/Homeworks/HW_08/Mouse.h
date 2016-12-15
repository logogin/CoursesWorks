// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#ifndef Mouse_h
#define Mouse_h
#include <iostream.h>
#include "Mammals.h"
#include "Herbivorous.h"

class Mouse: public Mammals, public Herbivorous
{
	public:
		 virtual void PrintAnimalName( ) const
		 {
				Mammals::PrintAnimalType( );
				cout<<"  Mouses ";
				Herbivorous::PrintAnimalEat( );
		 }
};
#endif
