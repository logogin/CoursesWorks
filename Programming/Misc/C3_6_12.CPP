#include <iostream.h>

class Rectangle
{
	public :
		Rectangle();
		void setlength(float); 
		void setwidth(float);
		float perimeter();
		float area();
		float getlength();
		float getwidth();
	private :
		float length;
		float width;
};

Rectangle::Rectangle()
{
	length=1;
	width=1;
}

void Rectangle::setlength(float l)
{
	if (l>=0.0&&l<=20.0)
		length=l;
}

void Rectangle::setwidth(float w)
{
	if (w>=0.0&&w<=20.0)
		width=w;
}

float Rectangle::getlength(void)
{
	return length;
}

float Rectangle::getwidth(void)
{
	return width;
}

float Rectangle::perimeter()
{
	return (2*(length+width));
}

float Rectangle::area()
{
	return (length*width);
}

void main()
{
	Rectangle rec;
	rec.setlength(3);
	rec.setwidth(4);
	cout <<"The length is : "<<rec.getlength()<<endl;
	cout <<"The width is : "<<rec.getwidth()<<endl;
	cout <<"The perimeter is : "<<rec.perimeter()<<endl;
	cout <<"The area is : "<<rec.area()<<endl;
}