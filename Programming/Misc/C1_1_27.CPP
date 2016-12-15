#include <iostream.h>

#define M_PI        3.14159265358979323846

void main()
{
	float radius;
	cout <<"Enter the radius of a circle : ";
	cin >> radius;
	cout <<endl<<"Diametr is : "<<2*radius<<endl;
	cout <<"Circumference is : "<<2*M_PI*radius<<endl;
	cout <<"Area is : "<<M_PI*radius*radius<<endl;
}
