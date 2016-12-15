#include <iostream.h>
#include <conio.h>
#include "Complex.h"
#include "CVector.h"
#include "CMatrix.h"

void main()
{
	unsigned short col1,row1,col2,row2;
	cout <<"Enter size of the first matrix (col,row): ";
	cin >>col1>>row1;
	cout <<"Enter the size of the second matrix (col,row): ";
	cin >>col2>>row2;
	ComplexMatrix Matrix1(col1,row1);
	ComplexMatrix Matrix2(col2,row2);
	cout<<"First Matrix :"<<endl;
	for (int i=0; i<row1; i++)
	{
		cout <<"Enter "<<col1<<" complex numbers for "<<
			i+1<<" vector (real,imaginary): ";
		cin>>Matrix1[i];
	}
	cout<<"Second Matrix :"<<endl;
	for (i=0; i<row2; i++)
	{
		cout <<"Enter "<<col2<<" complex numbers for "<<
			i+1<<" vector (real,imaginary): ";
		cin>>Matrix2[i];
	}
	Complex Num1=Matrix1[0][0],Num2=Matrix2[0][0];
	cout<<endl<<Num1<<" + "<<Num2<<" = "<<Num1+Num2<<endl;
	cout<<Num1<<" - "<<Num2<<" = "<<Num1-Num2<<endl;
	cout<<Num1<<" * "<<Num2<<" = "<<Num1*Num2<<endl;
	cout<<Num1<<" / "<<Num2<<" = "<<Num1/Num2<<endl;
	cout<<"~ "<<Num1<<" = "<<~Num1<<endl;
	cout<<Num1<<" ^ "<<Num2<<" = "<<(Num1^Num2)<<endl;
	cout<<Num1<<" == "<<Num2<<" = "<<(Num1==Num2)<<endl;
	cout<<Num1<<" != "<<Num2<<" = "<<(Num1!=Num2)<<endl;
	cout<<"Press any key to continue"<<endl;
	getch();
	ComplexVector Vec1=Matrix2[0],Vec2=Matrix2[0];
	if (col1==col2)
	{
		cout<<Vec1<<" + "<<Vec2<<" = "<<Vec1+Vec2<<endl;
		cout<<Vec1<<" - "<<Vec2<<" = "<<Vec1-Vec2<<endl;
		cout<<Vec1<<" * "<<Vec2<<" = "<<Vec1*Vec2<<endl;
		cout<<Vec1<<" ^ "<<Vec2<<" = "<<(Vec1^Vec2)<<endl;
		cout<<Vec1<<" & "<<Vec2<<" = "<<(Vec1&Vec2)<<endl;
		cout<<Vec1<<" | "<<Vec2<<" = "<<(Vec1|Vec2)<<endl;
		cout<<Vec1<<" == "<<Vec2<<" = "<<(Vec1==Vec2)<<endl;
		cout<<Vec1<<" != "<<Vec2<<" = "<<(Vec1!=Vec2)<<endl;
	}
	cout<<"~ "<<Vec1<<" = "<<~Vec1<<endl;
	cout<<"Press any key to continue"<<endl;
	getch();
	if ((col1==col2)&&(row1==row2))
	{
		cout<<Matrix1<<" + "<<endl<<Matrix2<<" = "<<endl<<Matrix1+Matrix2;
		cout<<"Press any key to continue"<<endl;
		getch();
		cout<<Matrix1<<" - "<<endl<<Matrix2<<" = "<<endl<<Matrix1-Matrix2;
		cout<<"Press any key to continue"<<endl;
		getch();
		cout<<Matrix1<<" & "<<endl<<Matrix2<<" = "<<endl<<(Matrix1&Matrix2);
		cout<<"Press any key to continue"<<endl;
		getch();
		cout<<Matrix1<<" | "<<endl<<Matrix2<<" = "<<endl<<(Matrix1|Matrix2);
		cout<<"Press any key to continue"<<endl;
		getch();
		cout<<Matrix1<<" == "<<endl<<Matrix2<<" = "<<(Matrix1==Matrix2)<<endl;
		cout<<"Press any key to continue"<<endl;
		getch();
		cout<<Matrix1<<" != "<<endl<<Matrix2<<" = "<<(Matrix1!=Matrix2)<<endl;
		cout<<"Press any key to continue"<<endl;
		getch();
	}
	if (row1==col2)
	{
		cout<<Matrix1<<" * "<<endl<<Matrix2<<" = "<<endl<<Matrix1*Matrix2;
		cout<<"Press any key to continue"<<endl;
		getch();
	}
	if (row1==row2)
	{
		cout<<Matrix1<<" ^ "<<endl<<Matrix2<<" = "<<endl<<(Matrix1^Matrix2);
		cout<<"Press any key to continue"<<endl;
		getch();
	}
	cout<<" ~ "<<endl<<Matrix1<<" = "<<endl<<~Matrix1;
	cout<<"Press any key to continue"<<endl;
	getch();
	cout<<" ! "<<endl<<Matrix1<<" = "<<endl<<!Matrix1<<flush;
}