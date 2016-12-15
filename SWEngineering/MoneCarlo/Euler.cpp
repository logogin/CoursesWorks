#include <iostream.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef long double l_double;

l_double y;

const l_double a_value=/*-4.0*/0.0;
const l_double b_value=/*3.0*/1.0;
const l_double __y0=/*24.0*/1.0;

unsigned long n/*=10000*/;

l_double f(const l_double value)
{
	return /*powl(value,2)*sinl(cosl(value))*/4.0;
}

l_double f1(const l_double value)
{
	return /*value*(2*sinl(cosl(value))-value*sinl(value)*cosl(cosl(value)))*/0.0;
}

l_double f11(const l_double value)
{
	return /*sinl(cosl(value))*(2-powl(value*sinl(value),2))-
		value*cosl(cosl(value))*(4*sinl(value)+value*cosl(value))*/0.0;
}

l_double g(const l_double value)
{
	return /*sinhl(coshl(value))*/1-value;
}

l_double g1(const l_double value)
{
	return /*sinhl(value)*coshl(coshl(value))*/-1.0;
}

l_double g11(const l_double value)
{
	return /*sinhl(coshl(value))*powl(sinhl(value),2)+coshl(coshl(value))*coshl(value)*/0.0;
}

l_double y1(const l_double x_value,const l_double y_value)
{
	return f(x_value)*y_value+g(x_value);
}

l_double y11(const l_double x_value,const l_double y_value)
{
	return f1(x_value)*y_value+y1(x_value,y_value)*f(x_value)+g1(x_value);
}

l_double y111(const l_double x_value,const l_double y_value)
{
	return f11(x_value)*y_value+y11(x_value,y_value)*f(x_value)+
		2*f1(x_value)*y1(x_value,y_value)+g11(x_value);
}

l_double t2(const l_double x_value,const l_double y_value,const l_double h_value)
{
	return y1(x_value,y_value)+(h_value/2)*y11(x_value,y_value)+
		(powl(h_value,2)/6)*y111(x_value,y_value);
}
const l_double error=0.0000001;
void main()
{
	
	bool flag=false;
	bool end_flag=false;
	cout.precision(20);
	l_double y;
	l_double h;
	n=1;
	
	while (!end_flag)
	{
		n*=2;
		l_double x=a_value;
		y=__y0;
		h=(b_value-a_value)/n;
		l_double previous;
		for (int i=0; i<n; i++)
		{
			y=y+h*t2(x,y,h);
			x+=h;
		}
		if (!flag)
		{
			previous=y;
			flag=true;
		}
		else
			if (error>=fabsl(previous-y))
				end_flag=true;
			else
			{
				cout<<"{result="<<y<<",n="<<n<<",h="<<h<<",prev="<<previous<<",error="<<fabsl(previous-y)<<"%}"<<endl;
				previous=y;
			}

	}
	cout<<"{result="<<y<<",n="<<n<<",h="<<h<<"}"<<endl;
	cout<<"Integral : "<<y-__y0<<endl;
}