// 29.12.2000 Dmitry Zavyalov (c)
//
// Program " RGB "

#include <iostream.h>
#include "tscreen.h"

template<class T>
ostream & operator << (ostream &output, const Pixel<T> &rPix)
{
	output << " R" << (unsigned long)rPix.m_Red
		   << " G" << (unsigned long)rPix.m_Green
		   << " B" << (unsigned long)rPix.m_Blue << "\t";

	return output;
}
template<class T>
istream & operator >> (istream &input, Pixel<T> &rPix)
{
	input >> rPix.m_Red >>  rPix.m_Green >> rPix.m_Blue ;

	return input;
}

main()
{
/* check casting pixel */


	Pixel<unsigned short>	pix1(1500);
	Pixel<char>				pix2;
	Pixel<unsigned short>	pix3;
	Pixel<unsigned long>	pix4(78131);

	cout << pix1 << endl;

	cout << pix2 << endl;

	pix2 = pix1.CastChar();
	cout << pix2 << endl;

	cout << pix3 << endl;

	pix3 = pix2.CastShort();
	cout << pix3 << endl;

	pix3 = pix1.CastShort();
	cout << pix3 << endl;

	cout << pix4 << endl;

	pix2 = pix4.CastChar();
	cout << pix2 << endl;

	pix3 = pix4.CastShort();
	cout << pix3 << endl;

	pix4 = pix1.CastLong();
	cout << pix4 << endl;

/* ********CHECK IF FIRST MATRIX IS SUBMATRIX OF SECOND ***** */

	Screen<char, 2, 2> picture1;
	Screen<char, 3, 3> picture2;
	Proccess<char, 2, 2> proc_pict1;
	Proccess<char, 3, 3> proc_pict2;

	proc_pict1.FillPicture(picture1);
	proc_pict1.PrintPicture(picture1);

	proc_pict2.FillPicture(picture2);

	if(proc_pict1.CompPictures(picture1, picture2))
		cout << "\nTRUE\n";
	else
		cout << "\nFALSE\n";

/* Check casting of matrix */
/*/
	Screen<char, 2, 2> picture1;
	Screen<unsigned short, 2, 2> picture2;

	picture2 = picture1.CastShort();


	picture2 = picture1.CastShort();
	if(picture1 == picture2)
	{
		proc_pict.FillPicture(picture2);
		proc_pict.PrintPicture(picture2);
	}
/*/
	return 0;
}
