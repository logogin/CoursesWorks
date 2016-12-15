// 10.01.2001 Dmitry Zavyalov (c)
//
// Program " Male Female Child "

#include <iostream.h>
#include <stdlib.h>
#include <time.h>
#include "child.h"
#include "male.h"
#include "female.h"

Child::Child(): Male(), Female()	//	Constructor
{
	int temp;
	srand( (unsigned)time( NULL ) );
	temp = 1+(rand()%10);
	switch (temp)
	{
	case 1: SetSkin( Male::GetSkin() );
			SetHair( Male::GetHair() );
			SetEye( Male::GetEye() );
			break;

	case 2: SetSkin( Female::GetSkin() );
			SetHair( Female::GetHair() );
			SetEye( Female::GetEye() );
			break;

	case 3:case 4:
			SetSkin( Male::GetSkin() < Female::GetSkin() ?
				Male::GetSkin() : Female::GetSkin() );
			SetHair( Male::GetHair() < Female::GetHair() ?
				Male::GetHair() : Female::GetHair() );
			SetEye( Male::GetEye() < Female::GetEye() ?
				Male::GetEye() : Female::GetEye() );
			break;

	case 5: case 6: case 7: case 8: case 9:
			SetSkin( Male::GetSkin() > Female::GetSkin() ?
				Male::GetSkin() : Female::GetSkin() );
			SetHair( Male::GetHair() > Female::GetHair() ?
				Male::GetHair() : Female::GetHair() );
			SetEye( Male::GetEye() > Female::GetEye() ?
				Male::GetEye() : Female::GetEye() );
			break;

	case 10:
		 m_Skin = 1+rand()%4;
		 m_Hair = 1+rand()%4;
		 m_Eye = 1+rand()%3;
		 break;
	}
	SetHigh( ( Male::GetHigh() + Female::GetHigh() )/ 2 + 10 );
	SetWeigth(( (Male::GetWeigth() + Female::GetWeigth())/ 2 )* 1.05);
}

void Child::SetSkin( int Skin )
{
	m_Skin = Skin;
}

void Child::SetHair( int Hair )
{
	m_Hair = Hair;
}

void Child::SetEye( int Eye )
{
	m_Eye = Eye;
}

void Child::SetHigh( float High )
{
	m_High = High;
}

void Child::SetWeigth( float Weigth )
{
	m_Weigth = Weigth;
}

int Child::GetSkin( void )
{
	return m_Skin;
}

int Child::GetHair( void )
{
	return m_Hair;
}

int Child::GetEye( void )
{
	return m_Eye;
}

float Child::GetHigh( void )
{
	return m_High;
}

float Child::GetWeigth( void )
{
	return m_Weigth;
}

void Child::Print( void )
{
	cout<<"\nMale Skin Color: ";
	switch ( Male::GetSkin() )
	{
	case 1: cout<<"White\n"; break;
	case 2: cout<<"Yellow\n"; break;
	case 3: cout<<"Red\n"; break;
	case 4: cout<<"Black\n"; break;
	}

	cout << "Male Hair Color: ";
	switch ( Male::GetHair() )
	{
	case 1: cout<<"Blond\n"; break;
	case 2: cout<<"Red\n"; break;
	case 3: cout<<"Brown\t\t"; break;
	case 4: cout<<"Black\t\t"; break;
	}

	cout << "Male Eye Color: ";
	switch ( Male::GetEye() )
	{
	case 1: cout<<"Blue\n"; break;
	case 2: cout<<"Brown\n"; break;
	case 3: cout<<"Black\n"; break;
	}

	cout<<"Male High is: "
		<<Male::GetHigh()
		<<endl;

	cout<<"Male Weigth is: "
		<<Male::GetWeigth()
		<<endl;

	cout<<"\nFemaleSkin Color: ";
	switch ( Female::GetSkin() )
	{
	case 1: cout<<"White\n"; break;
	case 2: cout<<"Yellow\n";break;
	case 3: cout<<"Red\n"; break;
	case 4: cout<<"Black\n"; break;
	}

	cout << "Female Hair Color: ";
	switch ( Female::GetHair () )
	{
	case 1: cout<<"Blond\n"; break;
	case 2: cout<<"Red\n"; break;
	case 3: cout<<"Brown\n"; break;
	case 4: cout<<"Black\n"; break;
	}

	cout << "Female Eye Color: ";
	switch ( Female::GetEye() )
	{
	case 1: cout<<"Blue\n"; break;
	case 2: cout<<"Brown\n"; break;
	case 3: cout<<"Black\n"; break;
	}

	cout<<"Female High is: "
		<<Female::GetHigh()
		<<endl;

	cout<<"Female Weigth is : "
		<<Female::GetWeigth()
		<<endl;

	cout<<"\nChild Skin Color: ";
	switch ( GetSkin() )
	{
	case 1: cout<<"White\n"; break;
	case 2: cout<<"Yellow\n"; break;
	case 3: cout<<"Red\n"; break;
	case 4: cout<<"Black\n"; break;
	}

	cout<<"Child Hair Color: ";
	switch ( GetHair() )
	{
	case 1: cout<<"Blond\n"; break;
	case 2: cout<<"Red\n"; break;
	case 3: cout<<"Brown\n"; break;
	case 4: cout<<"Black\n"; break;
	}

	cout<<"Child Eye Color: ";
	switch ( GetEye() )
	{
	case 1: cout<<"Blue\n"; break;
	case 2: cout<<"Brown\n"; break;
	case 3: cout<<"Black\n"; break;
	}

	cout<<"Child High is: "
		<< GetHigh()
		<<endl;
	cout<<"Child Weigth is: "
		<<GetWeigth()
		<<endl;
}
