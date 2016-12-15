// 10.01.2001 Dmitry Zavyalov (c)
//
// Program " Male Female Child "

#include <iostream.h>
#include "male.h"

Male::Male( void )
{
	int Skin, Hair, Eye;
	float High, Weigth;

	cout<<"\n1-White, 2-Yellow, 3-Red, 4-Black\n";
	cout<<"Enter number the Color of Men Skin:> ";
	cin >>Skin;
	SetSkin( Skin );

	cout<<"1-Blond, 2-Red, 3-Brown, 4-Black\n";
	cout<<"Enter number the Color of Men Hair:> ";
	cin >>Hair;
	SetHair( Hair );

	cout<<"1-Blue, 2-Brown, 3-Black\n";
	cout<<"Enter number the Color of Men Eye:> ";
	cin >>Eye;
	SetEye( Eye );

	cout<<"Enter the Men High in (cm):> ";
	cin >>High;
	SetHigh( High );

	cout<<"Enter the Men Weigth in (kg):> ";
	cin >>Weigth;
	SetWeigth( Weigth );
}

void Male::SetSkin( int Skin )
{
	if( Skin>0 && Skin<5 ) m_Skin = Skin;
	else m_Skin = 1;
}

void Male::SetHair( int Hair )
{
	if( Hair>0 && Hair<5 ) m_Hair = Hair;
	else m_Hair = 1;
}

void Male::SetEye( int Eye )
{
	if( Eye>0 && Eye<4 ) m_Eye = Eye;
	else m_Eye = 1;
}

void Male::SetHigh( float High )
{
	if( High<=210 && High>=140 ) m_High = High;
	else m_High = 140;
}

void Male::SetWeigth( float Weigth )
{
  if( Weigth>=45 && Weigth<=130 ) m_Weigth = Weigth;
  else m_Weigth = 45;
}

int Male::GetSkin( void )
{
   return m_Skin;
}

int Male::GetHair( void )
{
   return m_Hair;
}

int Male::GetEye( void )
{
   return m_Eye;
}

float Male::GetHigh( void )
{
   return m_High;
}

float Male::GetWeigth( void )
{
   return m_Weigth;
}
