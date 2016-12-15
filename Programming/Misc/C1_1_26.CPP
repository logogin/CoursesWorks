#include <iostream.h>
#include <iomanip.h>

void main ()
{
	int n1;
	int n2;
	int n3;
	
	cout <<"Enter the 1-st number : ";
	cin >>n1;
	cout <<"Enter the 2-nd number : ";
	cin >>n2;
	cout <<"Enter the 3-th number : ";
	cin >>n3;

	cout <<"Sum is "<<n1+n2+n3<<endl;
	cout <<"Average is "<<(float)(n1+n2+n3)/3<<endl;
	cout <<"Prodact is "<<n1*n2*n3<<endl;

	if (n1>=n2)
	{
		n1+=n2;n2=n1-n2;n1-=n2;
	}
	if (n1>=n3)
	{
		n1+=n3;n3=n1-n3;n1-=n3;
	}
	if (n2>=n3)
	{
		n2+=n3;n3=n2-n3;n2-=n3;
	}

	cout <<"Smallest is : "<<n1<<endl;
	cout <<"Largest is :"<<n3<<endl;

}