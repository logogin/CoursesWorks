// 08.12.2000 Dmitry Zavyalov (c)
//
// 6.13 Subtle Rectangle ...

#include <iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

#include "Rectangle.h"


Rectangle::Rectangle(void)
{			               //constructor
  Length=Width=Perim=Are=x1=x2=x3=x4=y1=y2=y3=y4=1;
}


Rectangle::~Rectangle(void)
{ 				       //destructor
  cout<<"\n\nObject closed!";
}


float Rectangle::Cal_Length(float x_1,float y_1,float x_2,float y_2)
{
  float Sum1=x_1+y_1, Sum2=x_2+y_2;
  if(Sum1>Sum2){
	  Length=(float)sqrt(((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2)));}
  if(Sum1<Sum2){
	  Length=(float)sqrt(((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1)));}
  if(Sum1==Sum2) cout<<"Error";
 return Length;
}


float Rectangle::Cal_Width(float x_1,float y_1,float x_2,float y_2)
{
  float Sum1=x_1+y_1, Sum2=x_2+y_2;
  if(Sum1>Sum2){
  Width=(float)sqrt(((x_1-x_2)*(x_1-x_2))+((y_1-y_2)*(y_1-y_2)));}
  if(Sum1<Sum2){
  Width=(float)sqrt(((x_2-x_1)*(x_2-x_1))+((y_2-y_1)*(y_2-y_1)));}
  if(Sum1==Sum2) cout<<"Error";
 return Width;
}


float Rectangle::Perimeter(float Length, float Width)
{
  Perim=((Length*2)+(Width*2));         //calculation of PERIMETER
  return Perim;
}


float Rectangle::Area(float Length, float Width)
{
  Are=(Length*Width);                   //calculation of AREA
 return Are;
}


void Rectangle::PrintData(float Length,float Width,float Perim,
							float Are)
{
  cout<<"\nLength    = "<<Length;         //printing of results
  cout<<"\nWidth     = "<<Width;
  cout<<"\nPerimeter = "<<Perim;
  cout<<"\nArea      = "<<Are;
}


float Rectangle::WriteCoord1 (void)
{
  float Coord1;
  int   flag=0;
	cout<<"Enter the FIRST coordinate : "; cin>>Coord1;
  if(flag==1){
	 if(Coord1>=0.0 && Coord1<=20){
	 y1=Coord1; return y1;}
  }
  if(Coord1>=0.0 && Coord1<=20){
	x1=Coord1; flag=1; return x1;}
  return 1.0;
}


float Rectangle::WriteCoord2 (void)
{
  float Coord2;
  int   flag=0;
	cout<<"Enter the SECOND coordinate : "; cin>>Coord2;
  if(flag==1){
	 if(Coord2>=0.0 && Coord2<=20){
	 y2=Coord2; return y2;}
  }
  if(Coord2>=0.0 && Coord2<=20){
	x2=Coord2; flag=1; return x2;}
  return 1.0;
}


float Rectangle::WriteCoord3 (void)
{
  float Coord3;
  int   flag=0;
	cout<<"Enter the 3-TH coordinate : "; cin>>Coord3;
  if(flag==1){
	 if(Coord3>=0.0 && Coord3<=20){
	 y3=Coord3; return y3;}
  }
  if(Coord3>=0.0 && Coord3<=20){
	 x3=Coord3; flag=1; return x3;}
  return 1.0;
}


float Rectangle::WriteCoord4 (void)
{
  float Coord4;
  int   flag=0;
	cout<<"Enter the 4-TH coordinate : "; cin>>Coord4;
  if(flag==1){
	 if(Coord4>=0.0 && Coord4<=20){
	 y4=Coord4; return y4; }
  }
  if(Coord4>=0.0 && Coord4<=20){
	x4=Coord4; flag=1; return x4;}
  return 1.0;
}


void Rectangle::Square(float Length, float Width)
{
  if(Length<Width) {
   float help;
   help=Length; Length=Width; Width=help;
  }
  if(Length==Width) cout<<"\nThis is SQUARE!";
}
