#include <iostream.h>

void main ()
{
	int array[5];
	int max=-32768;
	int min=32768;
	for (int i=0; i<5; i++)
	{
		cout << "Enter the "<<i+1<<" integer number : ";
		cin >> array[i];
	}

	for (i=0; i<5; i++)
	{
		if (array[i]>max) max=array[i];
		if (array[i]<min) min=array[i];
	}

	cout<<"\n"<<"Maximal number is : "<<max<<"\n"
		<<"Minimal number is "<<min<<endl;

}