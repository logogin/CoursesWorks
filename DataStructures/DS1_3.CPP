#include <iostream.h>

unsigned long k=1;

unsigned long reverse(unsigned long number,unsigned long digit)
{
	if (number/10==0) 
	{
		k=digit;
		return number*digit/k;
	}
	else
		return reverse(number/10,digit/10)+(number%10)*digit/k;
}

void main ()
{
	unsigned long n1;
	unsigned long n2;
	cout <<"Enter the number : ";
	cin >> n1;
	n2=reverse(n1,1000000000);
	cout <<n1<<" + "<<n2<<" = "<<n1+n2<<endl;
}