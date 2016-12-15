#include <iostream.h>
#include <iomanip.h>
#include <math.h>

double f(double x)
{
	return x-sqrt(3);
}

void main()
{
	int k=11;
	double a=0;
	double b=2;
	unsigned int max_n=1+(unsigned int)((log10(abs(b-a))+k)/log10(2));
	double x1=a;
	double y1=f(a);
	double x2=b;
	double y2=f(b);
	double c=(a+b)/2;
	if ((f(a)*f(b))>0)
		cout <<"There are no roots in this section!!!"<<endl;
	else
	{
		for (unsigned int i=0; i<max_n; i++)
		{
			if ((y1*f(c))<0)
			{
				x2=c;
				y2=f(c);
			}
			else
			{
				x1=c;
				y1=f(c);
			}
			c=(x1+x2)/2;
		}
	}
	cout<<setiosflags(ios::fixed||ios::showpoint)
		 <<setprecision(12);
	cout<<c<<endl;
}