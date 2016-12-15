// 19.01.2001 Dmitry Zavyalov (c)
//
// Program " Animals "

#include <conio.h>
#include "Lion.h"
#include "Mouse.h"
#include "Shark.h"
#include "Carp.h"

void main( void )
{
	Lion  Ln;
	Mouse Ms;
	Shark Sh;
	Carp  Cr;

	Ln.PrintAnimalName();
	Ms.PrintAnimalName();
	Sh.PrintAnimalName();
	Cr.PrintAnimalName();

	getch();
}
