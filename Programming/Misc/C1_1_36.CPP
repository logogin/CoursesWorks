#include <iostream.h>
#include <iomanip.h>

void main ()
{
	int number;
	int deviser=10000;
	cout <<"Enter the five-digit number : ";
	cin >> number;

	for (int i=0; i<5; i++)
	{
		cout <<number/deviser<<setw(4);
		number%=deviser;
		deviser/=10;
	}

	cout<<endl;
}