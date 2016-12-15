// 10.01.2001 Dmitry Zavyalov (c)
//
// Program " Male Female Child "

#include <iostream.h>
#include "female.h"

Female::Female( void )
{
		int Skin, Hair, Eye;
		float High, Weigth;

		cout<<"\n1-White, 2-Yellow, 3-Red, 4-Black\n";
		cout << "Enter number the Color of Female Skin: ";
		cin >> Skin;
		SetSkin( Skin );

		cout<<"1-Blond, 2-Red, 3-Brown, 4-Black\n";
		cout << "Enter number the Color of Female Hair: ";
		cin >> Hair;
		SetHair( Hair );

		cout<<"1-Blue, 2-Brown, 3-Black\n";
		cout << "Enter number the Color of Female Eye: ";
		cin >> Eye;
		SetEye( Eye );

		cout << "Enter the Female High in (cm): ";
		cin >> High;
		SetHigh( High );

		cout << "Enter the Female Weigth in (kg): ";
		cin >> Weigth;
		SetWeigth( Weigth );
}

void Female::SetSkin( int Skin )
{
	if( Skin>0 && Skin<5 ) m_Skin = Skin;
	else m_Skin = 1;
}

void Female::SetHair( int Hair )
{
	if( Hair>0 && Hair<5 ) m_Hair = Hair;
	else m_Hair = 1;
}

void Female::SetEye( int Eye )
{
	if( Eye>0 && Eye<4 ) m_Eye = Eye;
	else m_Eye = 1;
}

void Female::SetHigh( float High )
{
	 if( High>=140 && High<=210 ) m_High = High;
	 else m_High = 140;
}

void Female::SetWeigth( float Weigth )
{
  if( Weigth>=45 && Weigth<=130 ) m_Weigth = Weigth;
  else m_Weigth = 45;
}

int Female::GetSkin( void )
{
   return m_Skin;
}

int Female::GetHair( void )
{
   return m_Hair;
}

int Female::GetEye( void )
{
   return m_Eye;
}

float Female::GetHigh( void )
{
   return m_High;
}

float Female::GetWeigth( void )
{
   return m_Weigth;
}
