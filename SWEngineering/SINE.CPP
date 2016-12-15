#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include "advanced.h"
#include <math.h>
void main ()
 {
  int maxx,maxy,deltax,deltay;
  float x,y,t;
  maxx=getmaxx();
  maxy=getmaxy();
  deltax=maxx/(4*M_PI);
  deltay=maxy/4;
  Init("D:\\BORLANDC\\BGI");
  t=-2*M_PI;
  while (t<=2*M_PI)
   {
   y=sin(t)*deltay;
   x=t*deltax;
   t+=.1;
   lineto(x+maxx/2,y+maxy/2);
   moveto(x+maxx/2,y+maxy/2);

   }
  getch();
  closegraph();
 }