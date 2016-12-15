// 30.11.2000 Dmitry Zavyalov (c)
//
// 6.12 Rectangle ...

#include <iostream.h>
#include "Rectangle.h"

Rectangle::Rectangle()	// Rectangle class Constructor
{
	length=1;
	width=1;
}

void Rectangle::SetLength( float Ln )
{
	int Integer=(int)Ln;

	if( Ln>=0 && Ln<=20 && (float)Integer!=Ln ) length=Ln;
}

void Rectangle::SetWidth( float Wd )
{
	int Integer=(int)Wd;

	if( Wd>=0 && Wd<=20 && (float)Integer!=Wd ) width=Wd;

}

float Rectangle::GetLength()
{
	return ( length );
}

float Rectangle::GetWidth()
{
	return ( width );
}

float Rectangle::Perimetr()
{
	return ( 2*(length+width) );
}

float Rectangle::Area()
{
	return ( length*width );
}
