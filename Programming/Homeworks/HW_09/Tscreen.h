// 29.12.2000 Dmitry Zavyalov (c)
//
// Program " RGB "

#ifndef TSCREEN_H
#define TSCREEN_H

#include "tpixel.h"
#include "tproccess.h"

	/* ******** SECOND TEMPLATE CLASS ******** */

template <class T, unsigned short usRow, unsigned short usCol>
class Screen;

template <class T, unsigned short usRow, unsigned short usCol>
class Screen
{
	friend void Proccess<T, usRow, usCol>::PrintPicture(const Screen<T, usRow, usCol>&);
	friend void Proccess<T, usRow, usCol>::FillPicture(Screen<T, usRow, usCol> &);

	public:
		Screen();//constructor
		Screen(const Screen<T, usRow, usCol> &);//copy constructor
		Screen<T, usRow, usCol> &operator+=(const Screen<T, usRow, usCol> &);//overloading addition assignment operator
		Screen<T, usRow, usCol> &operator-=(const Screen<T, usRow, usCol> &);//overloading subtraction assignment operator
		Screen<T, usRow, usCol> operator+(const Screen<T, usRow, usCol> &) const;//overloading addition  operator
		Screen<T, usRow, usCol> operator-(const Screen<T, usRow, usCol> &) const;//overloading subtraction  operator
		Screen<T, usRow, usCol> &operator=(const Screen<T, usRow, usCol> &);//overloading  assignment operator
		bool operator==(const Screen<T, usRow, usCol> &) const;//overloading equality operator
		Screen<char, usRow,usCol> CastChar()const;//casting to char
		Screen<unsigned short, usRow,usCol> CastShort()const;//casting to short
		Screen<unsigned long, usRow,usCol> CastLong()const;//casting to long

	private:
		Pixel<T> m_Screen[usRow][usCol];
};

//constructor
template <class T, unsigned short usRow, unsigned short usCol>
Screen<T, usRow, usCol>::Screen()
{
	unsigned short countRow, countCol;

	//init all elements of Screen to zero
	for(countRow = 0; countRow < usRow; countRow++)
			for(countCol = 0; countCol < usCol; countCol++)
				m_Screen[countRow][countCol] = 0;

}
//copy constructor
template<class T, unsigned short usRow, unsigned short usCol>
Screen<T, usRow, usCol>::Screen(const Screen<T,usRow, usCol> &rScreen)
{
	unsigned short countRow, countCol;

	//copy all elements of rScreen to current object
	for(countRow = 0; countRow < usRow; countRow++)
		for(countCol = 0; countCol < usCol; countCol++)
				m_Screen[countRow][countCol] = rScreen.m_Screen[countRow][countCol];
}
//overloading addition assignment operator
template<class T, unsigned short usRow, unsigned short usCol>
Screen<T, usRow, usCol> & Screen<T, usRow, usCol>::operator +=(const Screen<T, usRow, usCol> &rScreen)
{
	unsigned short countRow, countCol;

	for(countRow = 0; countRow < usRow; countRow++)
		for(countCol = 0; countCol < usCol; countCol++)
				m_Screen[countRow][countCol] += rScreen.m_Screen[countRow][countCol];

	return *this;
}
//overloading subtraction assignment operator
template<class T, unsigned short usRow, unsigned short usCol>
Screen<T, usRow, usCol> & Screen<T, usRow, usCol>::operator -=(const Screen<T, usRow, usCol> &rScreen)
{
	unsigned short countRow, countCol;

	for(countRow = 0; countRow < m_usRow; countRow++)
		for(countCol = 0; countCol < m_usCol; countCol++)
				m_Screen[countRow][countCol] -= rScreen.m_Screen[countRow][countCol];

	return *this;
}
//overloading equality operator
template<class T, unsigned short usRow, unsigned short usCol>
bool Screen<T, usRow, usCol>::operator==(const Screen<T, usRow, usCol> &rScreen) const
{
	unsigned short countRow, countCol;
	bool flag = true;

	for(countRow = 0; countRow < usRow && flag; countRow++)
		for(countCol = 0; countCol < usCol && flag; countCol++)
			if(!(m_Screen[countRow][countCol] == rScreen.m_Screen[countRow][countCol]))
				flag = false;

	return flag;
}
//overloading assignment operator
template<class T, unsigned short usRow, unsigned short usCol>
Screen<T, usRow, usCol> & Screen<T, usRow, usCol>::operator=(const Screen<T, usRow, usCol> &rScreen)
{
	unsigned short countRow, countCol;

	for(countRow = 0; countRow < usRow; countRow++)
		for(countCol = 0; countCol < usCol; countCol++)
			m_Screen[countRow][countCol] = rScreen.m_Screen[countRow][countCol];

	return *this;
}
//casting to char
template<class T, unsigned short usRow, unsigned short usCol>
Screen<char, usRow,usCol> Screen<T, usRow, usCol>:: CastChar()const
{
	Screen<char, usRow, usCol> TempScreen;
	unsigned short countRow, countCol;

	//cast each element of matrix to char
	for(countRow = 0; countRow < usRow; countRow++)
		for(countCol = 0; countCol < usCol; countCol++)
			m_Screen[countRow][countCol].CastChar();

	return TempScreen;
}
//casting to short
template<class T, unsigned short usRow, unsigned short usCol>
Screen<unsigned short, usRow,usCol> Screen<T, usRow, usCol>:: CastShort()const
{
	Screen<unsigned short, usRow, usCol> TempScreen;
	unsigned short countRow, countCol;

	//cast each element of matrix to short
	for(countRow = 0; countRow < usRow; countRow++)
		for(countCol = 0; countCol < usCol; countCol++)
			m_Screen[countRow][countCol].CastShort();

	return TempScreen;
}
//casting to long
template<class T, unsigned short usRow, unsigned short usCol>
Screen<unsigned long, usRow,usCol> Screen<T, usRow, usCol>:: CastLong()const
{
	Screen<unsigned long, usRow, usCol> TempScreen;
	unsigned short countRow, countCol;

	//cast each element of matrix to long
	for(countRow = 0; countRow < usRow; countRow++)
		for(countCol = 0; countCol < usCol; countCol++)
			m_Screen[countRow][countCol].CastLong();

	return TempScreen;
}

#endif
