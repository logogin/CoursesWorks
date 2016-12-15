#include <iostream.h>

void main ()
{
	int number;
	int multiple;
	cout <<"Enter the first number : ";
	cin >> number;
	cout <<"Enter the second number : ";
	cin >> multiple;

	if (number%multiple)
		cout <<"\nThe number "<<number<<" is not multiple of "<<multiple<<endl;
	else 
		cout <<"\nThe number "<<number<<" is multiple of "<<multiple<<endl;

}