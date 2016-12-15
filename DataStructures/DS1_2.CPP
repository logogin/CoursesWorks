#include <iostream.h>
#include <math.h>
#include <iomanip.h>

int steps;
double d;

double _exp(double result,double x)
{
	if (result>d)
	{
		steps++;
		result=result*x/steps;
		return result+_exp(result,x);
	}
	else return 1;
}
void main ()
{
	double x;	
	cout << "Enter x : ";
	cin >> x;
	cout << "Enter accuracy : ";
	cin >> d;
	cout << setiosflags(ios::fixed||ios::showpoint)
		 <<setprecision(14);
	cout <<endl<<"Exponent is : "<<_exp(1,x)<<endl;
	cout <<"The real value is : "<<exp(x)<<endl;
	cout << "Number of Recursion steps : " << steps+1 <<endl; 
}
