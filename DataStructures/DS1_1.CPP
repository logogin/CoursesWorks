#include <iostream.h>

unsigned long pow (int a,int b)
{
	if (b==1) return a;
	else return a*pow(a,b-1);
}

void main()
{
	int x,y;
	do
	{
		cout << "Enter x (1-20) : ";
		cin >> x;
		cout << "Enter y (1-20) : ";
		cin >>y;
		cout <<endl;
	}
	while (x>20||x<1||y>20||y<1);

	cout <<"x rised by y : "<<pow(x,y)<<endl;
}