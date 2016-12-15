#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <dos.h>
#include <bios.h>
void main ()
{
 int gdriver=DETECT,gmode;
 int resx,resy,radius,i=0,c;
 double x,y,delta,PI=3.14159;
 initgraph(&gdriver,&gmode,"D:\\BorlandC\\BGI");
 resx=0.5*getmaxx();
 resy=0.5*getmaxy();
 radius=resy;
 setcolor(15);
 circle(resx,resy,radius);
 delay(10);
 delta=2*PI/60;
 do
 {
 while (!kbhit())
  {
   setcolor(15);
   x=cos(delta*i);
   y=sin(delta*i);
   line(resx,resy,resx+int(x*resy),resy+int(y*resy));
   delay(100);
   setcolor(0);
   line(resx,resy,resx+int(x*resy),resy+int(y*resy));
   i=(i+1)%60;
  }
  }
  while (bioskey(1)!=27);
  getch();
  closegraph();
}