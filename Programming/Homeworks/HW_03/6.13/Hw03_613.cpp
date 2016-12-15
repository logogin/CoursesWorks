// 08.12.2000 Dmitry Zavyalov (c)
//
// 6.13 Subtle Rectangle ...


#include <iostream.h>
//#include <stdlib.h>
//#include <stdio.h>
//#include <conio.h>

#include "rectangle.h"

main(void)
{
 float Perim,Are,Length,Width,x1,x2,x3,x4,y1,y2,y3,y4;

 Rectangle A;                               //object of RECTANGLE
 x1=A.WriteCoord1();  y1=A.WriteCoord1();
 x2=A.WriteCoord2();  y2=A.WriteCoord2();
 x3=A.WriteCoord3();  y3=A.WriteCoord3();
 x4=A.WriteCoord4();  y4=A.WriteCoord4();

 Length=A.Cal_Length(x1,y1,x2,y2);         //Writing Length
 Width =A.Cal_Width (x2,y2,x3,y3);         //and Width
 A.Square(Length,Width);
 Perim= A.Perimeter(Length,Width);         //Perimeter is
 Are  = A.Area     (Length,Width);         //Area is
 A.PrintData(Length,Width,Perim,Are);      //printing
// getch();

 return (0);
}
