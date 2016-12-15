#include <iostream.h>
#include <math.h>
#include <stdlib.h>

class Rectangle
{
	public :
		Rectangle();
		~Rectangle();
		void setcoords();
		double perimeter();
		double area();
		double getlength();
		double getwidth();
		bool square();
	private :
		double coords[4][2];
		double length;
		double width;
				
};

Rectangle::~Rectangle()
{
	cout<<"Object closed!!!"<<endl; 
	for (int i=0; i<4; i++)
		coords[i][0]=coords[i][1]=0;
	exit(0);
}

void Rectangle::setcoords()
{
	bool flag=true;
	int i=0;
	double d1,d2,deltax,deltay;
	while (i<4&&flag)
	{
		cout<<"Enter x of the "<<i+1<<" coordinate : "<<flush;
		cin >>coords[i][0];
		cout<<"Enter y of the "<<i+1<<" coordinate : "<<flush;
		cin >>coords[i][1];
		if (coords[i][0]<0.0||coords[i][0]>20.0
			||coords[i][1]<0.0||coords[i][1]>20.0)
			flag=false;
		i++;
	}
	if (!flag) 
	{
		cout <<"Coordinates are not matching !!!"<<endl;
		Rectangle::~Rectangle();
	}
	else 
	{
		deltax=coords[0][0]-coords[2][0];
		deltay=coords[0][1]-coords[2][1];
		d1=sqrt(deltax*deltax+deltay*deltay);
		deltax=coords[1][0]-coords[3][0];
		deltay=coords[1][1]-coords[3][1];
		d2=sqrt(deltax*deltax+deltay*deltay);
		if (d1!=d2)
		{
			cout <<"It is not a rectangle!!!"<<endl;
			Rectangle::~Rectangle();
		}
		else
		{
			deltax=coords[0][0]-coords[1][0];
			deltay=coords[0][1]-coords[1][1];
			d1=sqrt(deltax*deltax+deltay*deltay);
			deltax=coords[1][0]-coords[2][0];
			deltay=coords[1][1]-coords[2][1];
			d2=sqrt(deltax*deltax+deltay*deltay);
			if (d1>=d2)
			{
				length=d1;
				width=d2;
			}
			else 
			{
				length=d2;
				width=d1;
			}
		}
	}
}

Rectangle::Rectangle()
{
	Rectangle::setcoords();
}

double Rectangle::getlength(void)
{
	return length;
}

double Rectangle::getwidth(void)
{
	return width;
}

double Rectangle::perimeter()
{
	return (2*(length+width));
}

double Rectangle::area()
{
	return (length*width);
}

bool Rectangle::square()
{
	if (length==width)
		return true;
	else
		return false;
}

void main()
{
	Rectangle rec;

	cout <<"The length is : "<<rec.getlength()<<endl;
	cout <<"The width is : "<<rec.getwidth()<<endl;
	cout <<"The perimeter is : "<<rec.perimeter()<<endl;
	cout <<"The area is : "<<rec.area()<<endl;
	if (rec.square())
		cout <<"This is a square"<<endl;
	else
		cout <<"This is not a square"<<endl;

}
