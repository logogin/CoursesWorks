#include <stdio.h>
#include <math.h>
#include <conio.h>

long double a=0.0;
long double b=1.0;
long double y=1;
int n=1000;

long double f (long double x)
{
	return /*(powl(x,2)*(sinl(cosl(x))))*/1.0;
}

long double g (long double x)
{
	return /*sinhl(coshl(x))*/0;
}
long double error=0.0001;
int main ()
{
	long double x=a;
	long double dx=((b-a)/n);
	bool flag=false,end_flag=false;
	
//	printf("( %.10llf , %.10llf )\n",x,y);
	n=1;
	while (!end_flag)
	{
		n*=2;
		long double x=a;
		long double dx=((b-a)/n);
		long double prev;
		for (int i=0;i<n;i++)
		{
			y=y+(y*f(x)+g(x))*dx;
			x+=dx;
			
		//	getch();
		}
		if (!flag)
		{
			prev=y;
			flag=true;
		}
		else
			if (error>=fabsl((prev-y)/y))
				end_flag=true;
			else
				prev=y;
			printf("( y=%lf , prev=%lf , n=%d , h=%lf , error=%lf )\n",y,prev,n,dx,error);
			getch();
	}
	
	//getch();
	return 0;
}