// 04.01.2001 Dmitry Zavyalov (c)
//
// Program " Expanded Class Complex "

#include "complex.h"

int main( void )
{
	float *pFloatComp, CompArr[2];
	Complex C1, C2, C3;

	C1(12.67,'I');
	cout<<C1
		<<endl;

	C1(1452.67,'r');
	cout<<C1
		<<endl;

	C2( 2.1,6.17);
	cout<<C2
		<<endl;

	return( 0 );
}
