// 29.12.2000 Dmitry Zavyalov (c)
//
// Program " RGB "

#ifndef TPIXEL_H
#define TPIXEL_H
#include <math.h>
#include <iostream.h>

template<class T>
class Pixel
{
	friend ostream & operator << (ostream &output, const Pixel<T> &);
	friend istream & operator >> (istream &input, Pixel<T> &);
public:
	//constructor
	Pixel(T r = 0, T g = 0, T b = 0)
	{
		SetPix(r, g, b);
	}
	//set values for  Pixel
	void SetPix(T r, T g, T b)
	{
		m_Green = g;
		m_Blue = b;
		m_Red = r;
	}

	Pixel(const Pixel<T> &);	//copy constructor
	Pixel<T> &operator+=(const Pixel<T> &);//overloading addition assignment operator
	Pixel<T> &operator-=(const Pixel<T> &);//overloading subtraction assignment operator
	Pixel<T> operator+(const Pixel<T> &) const;//overloading addition operator
	Pixel<T> operator-(const Pixel<T> &) const;//overloading subtraction operator
	Pixel<T> &operator=(const Pixel<T> &);//overloading  assignment operator
	bool operator==(const Pixel<T> &) const;//overloading equality operator
	bool operator!=(const Pixel<T> &) const;//overloading equality operator
	Pixel<char> CastChar()const;//casting to char
	Pixel<unsigned short> CastShort()const;//casting to short
	Pixel<unsigned long> CastLong()const;//casting to long
private:
	T m_Green;
	T m_Blue;
	T m_Red;
};

//copy constructor
template <class T>
Pixel<T>::Pixel(const Pixel<T> &rPixel)
{
	m_Green = rPixel.m_Green;
	m_Blue = rPixel.m_Blue;
	m_Red = rPixel.m_Red;
}

//overloading addition assignment operator
template <class T>
Pixel<T> & Pixel<T>::operator +=(const Pixel<T> &rPixel)
{
	T max;
	max = sizeof(T) * 256; //

	m_Green += rPixel.m_Green;
	if(m_Green < 0 )  m_Green = 0;
	if(m_Green > max)  m_Green = max;

	m_Blue += rPixel.m_Blue;
	if(m_Blue < 0 )  m_Blue = 0;
	if(m_Blue > max)  m_Blue = max;

	m_Red += rPixel.m_Red;
	if(m_Red < 0 )  m_Red = 0;
	if(m_Red > max)  m_Red = max;

	return *this;
}

//overloading subtraction assignment operator
template <class T>
Pixel<T> & Pixel<T>::operator -=(const Pixel<T> &rPixel)
{
	T max;
	max = sizeof(T) * 256;//max value it can be save in variable of the type T

	m_Green -= rPixel.m_Green;
	if(m_Green < 0 )  m_Green = 0;
	if(m_Green > max)  m_Green = max;

	m_Blue -= rPixel.m_Blue;
	if(m_Blue < 0 )  m_Blue = 0;
	if(m_Blue > max)  m_Blue = max;

	m_Red -= rPixel.m_Red;
	if(m_Red < 0 )  m_Red = 0;
	if(m_Red > max)  m_Red = max;

	return *this;
}

//overloading addition operator
template <class T>
Pixel<T> Pixel<T>::operator +(const Pixel<T> &rPixel) const
{
	Pixel<T> temp(*this);

	temp += rPixel;

	return temp;
}

//overloading subtraction  operator
template <class T>
Pixel<T> Pixel<T>::operator -(const Pixel<T> &rPixel) const
{
	Pixel<T> temp(*this);

	temp -= rPixel;

	return temp;
}

//overloading equality operator
template <class T>
bool Pixel<T>::operator==(const Pixel<T> &rPixel) const
{
	return (m_Green == rPixel.m_Green && m_Blue == rPixel.m_Blue && m_Red == rPixel.m_Red);
}

//overloading anequality operator
template <class T>
bool Pixel<T>::operator!=(const Pixel<T> &rPixel) const
{
	return (m_Green != rPixel.m_Green || m_Blue != rPixel.m_Blue || m_Red != rPixel.m_Red);
}

//overloading assignment operator
template <class T>
Pixel<T> & Pixel<T>::operator =(const Pixel<T> &rPixel)
{
	if(&rPixel != this)//check for self-assignment
	{
		m_Green = rPixel.m_Green;
		m_Blue = rPixel.m_Blue;
		m_Red = rPixel.m_Red;
	}

	return *this;
}
//casting to char
template <class T>
Pixel<char> Pixel<T>::CastChar()const
{
	Pixel<char> tempPix;

	short S1 = sizeof(m_Red);
	short S2 = sizeof(char);

		tempPix.SetPix((char)(m_Red/(unsigned long)pow(2, 8*(S1-S2))), (char)(m_Green/(unsigned long)pow(2, 8*(S1-S2))), (char)(m_Blue/(unsigned long)pow(2, 8*(S1-S2))));

	return tempPix;
}
//casting to short
template <class T>
Pixel<unsigned short> Pixel<T>::CastShort()const
{
	Pixel<unsigned short> tempPix;

	short S1 = sizeof(m_Red);//check size of variable of current object
	short S2 = sizeof(unsigned short);

	if(S1 > S2)//need to compress to less size
		tempPix.SetPix((unsigned short)(m_Red/(unsigned long)pow(2, 8*(S1-S2))), (unsigned short)(m_Green/(unsigned long)pow(2, 8*(S1-S2))), (unsigned short)(m_Blue/(unsigned long)pow(2, 8*(S1-S2))));
	else
		//need to strength
		tempPix.SetPix((unsigned short)(m_Red*(unsigned long)pow(2, 8*(S2-S1))), (unsigned short)(m_Green*(unsigned long)pow(2, 8*(S1-S2))), (unsigned short)(m_Blue*(unsigned long)pow(2, 8*(S1-S2))));

	return tempPix;
}
//casting to long
template <class T>
Pixel<unsigned long> Pixel<T>::CastLong()const
{
	Pixel<unsigned long> tempPix;

	short S1 = sizeof(m_Red);//check size of variable of current object
	short S2 = sizeof(unsigned long);

	tempPix.SetPix((unsigned long)(m_Red*(unsigned long)pow(2, 8*(S2-S1))), (unsigned long)(m_Green*(unsigned long)pow(2, 8*(S1-S2))), (unsigned long)(m_Blue*(unsigned long)pow(2, 8*(S1-S2))));

	return tempPix;
}

#endif
