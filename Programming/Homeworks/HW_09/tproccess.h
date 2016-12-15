// 29.12.2000 Dmitry Zavyalov (c)
//
// Program " RGB "

#ifndef TPROCCESS_H
#define TPROCCESS_H

#include <iostream.h>
#include "tscreen.h"

template <class T, unsigned short usRow, unsigned short usCol>
class Screen;

template<class T, unsigned short usRow, unsigned short usCol>
class Proccess
{
public:
	void PrintPicture(const Screen<T, usRow, usCol>&);//print matrix
	void FillPicture(Screen<T, usRow, usCol>&);//obtain values for m,atrix's elements
	//check if first matrix is submatrix of second
	template<class T, unsigned short usRow, unsigned short usCol, unsigned short usRow1, unsigned short usCol1>
	bool CompPictures(Screen<T, usRow, usCol>&rPict, Screen<T, usRow1, usCol1>&rPict1);

};

//printing the matrix of pixels
template <class T, unsigned short usRow, unsigned short usCol>
void Proccess<T, usRow, usCol>::PrintPicture(const Screen<T, usRow, usCol>& rPicture)
{
	int countRow, countCol;

	for(countRow = 0; countRow < usRow; countRow++)
	{
		for(countCol = 0; countCol < usCol; countCol++)
			cout << rPicture.m_Screen[countRow][countCol];
		cout << endl;
	}
}

//filling the matrix of pixels (obtain values from user)
template <class T, unsigned short usRow, unsigned short usCol>
void Proccess<T, usRow, usCol>::FillPicture(Screen<T, usRow, usCol> &rPicture)
{
	int countRow, countCol;

	cout << "\nEntere 3 values for RGB of " << usRow * usCol <<" elements of matrix:";

	for(countRow = 0; countRow < usRow; countRow++)
		for(countCol = 0; countCol < usCol; countCol++)
		{
			cin >> rPicture.m_Screen[countRow][countCol];
		}
}

template<class T>
bool ex_eq_matrix(Pixel<T> *arr1, Pixel<T> *arr2, int row, int col, int col1)
/* function checks two arrays which different only column numbers */
/* if an array is subarray of other */
{
	// returns true in the case of coincedence and false otherwise
	// arr1 the smaller matrix, row and col its rows and columns numbers respectively;
	// ar2 the larger matrix, col1 its columns number
	int i, j;

	for(i = 0; i < row; i++)
		for(j = 0; j < col; j++)
			if((*(arr1 + j + i * col)) != (*(arr2 + j + i * col1)))
				return false;
	return true;
}

template<class T, unsigned short usRow, unsigned short usCol, unsigned short usRow1, unsigned short usCol1>
bool Proccess<T, usRow, usCol>::CompPictures(Screen<T, usRow, usCol>&rPict, Screen<T, usRow1, usCol1>&rPict1)
{
	int i, j;
	bool res;

	if((usRow == usRow1) && (usCol == usCol1))//dimensions of arrays are equale respectively
		return(rPict == rPict1);
	else if(((usRow1 > usRow) && (usCol1 > usCol)) || ((usRow1 > usRow) && (usCol1 == usCol)) || ((usRow1 == usRow) && (usCol1 > usCol)))
	{
		res = false;
		for(i = 0; i <= (usRow1 - usRow); i++)
			for(j = 0; j <= (usCol1 - usCol); j++)
			{
				if(ex_eq_matrix(rPict.m_Screen, (rPict1.(m_Screen + j + i * usCol1)), usRow, usCol, usCol1))
					res = true;
			}
		res = false;
	}
	else
			res = false;

	return res;
}

#endif
