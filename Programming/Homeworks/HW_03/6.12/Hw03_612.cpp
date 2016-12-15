// 30.11.2000 Dmitry Zavyalov (c)
//
// 6.12 Rectangle ...

#include <iostream.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <conio.h>

#include "rectangle.h"
main(void)
{
	Rectangle R1;
	
	R1.SetLength(12.8);
	cout<<"Length R1 = "
		<<R1.GetLength()
		<<endl;

	R1.SetWidth(4.6);
	cout<<"Width R1 = "
		<<R1.GetWidth()
		<<endl;

	cout<<"Perimetr R1 = "
		<<R1.Perimetr()
		<<endl;

	cout<<"Area R1 = "
		<<R1.Area()
		<<endl;

	return (0);
}