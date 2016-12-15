#include <iostream.h>
#include <iomanip.h>

void main()
{
	long value1=200000;
	long value2;

	long *lPtr; // a)

	lPtr=&value1; // b)

	cout <<"The value of the object pointed to by lPtr : "
		<<*lPtr<<endl; // c)

	value2=*lPtr; // d)

	cout <<"The value of value2 : "<<value2<<endl; // e)
	
	cout.setf(ios::hex, ios::uppercase);
	cout <<"The address of value1 : "<<&value1<<endl; // f)

	cout <<"The address stored in lPtr : "<<lPtr<<endl; // g)

}