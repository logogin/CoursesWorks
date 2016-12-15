// 17.12.2000 Dmitry Zavyalov (c)
//
// Program " Class Complex "

#include "complex.h"
#include "c_vector.h"
#include "c_matrix.h"

int main( void )
{
	char Temp;
	ComplexMatrix Mtr1(2,2), Mtr2(2,2), Mtr3(2,2);

	cout<<"I want to check my HomeWork N5 by executing all Complex Matrix operetors...\n"
		<<"First of all we want to fill cMatrix 2x2: there are 2 cVectors & 3 cNumbers.\n"
		<<"Example of Input cNumber (two numbers with Space between):2 3\n"
		<<"Example of Input cVector consist of 3 cNumbers:4 1 8 3 6 11\n"
		<<"My Matrix consist of 4 cNumbers (there are 8 simple numbers)...\n"
		<<"\nPlease, Input First Complex Matrix:\n";
	cin >>Mtr1;
	cout<<"\nPlease, Input Second Complex Matrix:\n";
	cin >>Mtr2;

	cout<<"\nOur Matrix N1:\n"
		<<Mtr1
		<<"\nOur Matrix N2:\n"
		<<Mtr2
		<<endl;

	cout<<"\nFor Check Operator + ( Matrix1 + Matrix2 ) press Letter & Enter ....\n";
	cin >>Temp;
	Mtr3 = Mtr1 + Mtr2;
	cout<<Mtr3;

	cout<<"\nFor Check Operator - ( Matrix1 - Matrix2 ) press Letter & Enter ....\n";
	cin >>Temp;
	Mtr3 = Mtr1 - Mtr2;
	cout<<Mtr3;

	cout<<"\nFor Check Operator & ( Matrix1 & Matrix2 ) press Letter & Enter ....\n";
	cin >>Temp;
	Mtr3 = Mtr1 & Mtr2;
	cout<<Mtr3;

	cout<<"\nFor Check Operator | ( Matrix1 | Matrix2 ) press Letter & Enter ....\n";
	cin >>Temp;
	Mtr3 = Mtr1 | Mtr2;
	cout<<Mtr3;

	cout<<"\nFor Check Operator ! ( Matrix1 ) press Letter & Enter ....\n";
	cin >>Temp;
	Mtr3 = !Mtr1;
	cout<<Mtr3;

	cout<<"\nFor Check Operator ^ ( Matrix1 ^ Matrix2 ) press Letter & Enter ....\n";
	cin >>Temp;
	Mtr3 = Mtr1 ^ Mtr2;
	cout<<Mtr3;

	cout<<"\n			THE END\n";
	return( 0 );
}
