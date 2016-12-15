#include <iostream.h>
#include "file.h"

File::File(int a, int b)
{
	x=a;
	y=b;
}

void File::Print()
{
	cout<<"x="<<x<<endl;
	cout<<"y="<<y<<endl;
}

File File::Add( const File &J2)
{
	File result;
	result.x = x+J2.x;
	result.y = y+J2.y;

	return (result);
}