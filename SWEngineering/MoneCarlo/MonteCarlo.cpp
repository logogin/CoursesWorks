#include <iostream.h>
#include <iomanip.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M_PI 2.7182818284590452353602874713527
long double function(const long double value);

const long double left_value=-4.0;
const long double right_value=-4.0;


const long double bottom_value=pow(-4,3);
const long double top_value=pow(4.0,3);//function(left_value)/*pow(3,3)*/;

unsigned long k=100000;
unsigned long m=0;

long double generator(const long double a_value,const long double range)
{
	return a_value+((long double)rand()/RAND_MAX)*range;
}

long double function(const long double value)
{
	return /*sinh(cosh(value))*//*sin(value)*//*sin(2000*value)*/pow(value,3);
}

void main()
{
	long double x,y;
	srand((unsigned)time(NULL));
	for (unsigned int i=0; i<k; i++)
	{
		x=generator(left_value,right_value-left_value);
		y=generator(0.0,top_value-bottom_value);
		if ((function(x)-bottom_value)>y)
			m++;
		
	}
	cout.precision(150);
	cout<<(right_value-left_value)*(top_value-bottom_value)*((long double)m/k)
		+bottom_value*(right_value-left_value)<<endl<<exp(1)-1.0<<endl<<RAND_MAX<<endl;
	cout<<"Error is about "<<1/sqrt(k)<<endl;
}