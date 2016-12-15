// 08.12.2000 Dmitry Zavyalov (c)
//
// 6.13 Subtle Rectangle ...

#ifndef Fi_H
#define Fi_H

class Rectangle
{				               //declaration of CLASS
   private:
		  float Length,Width,Perim,Are;
		  float x1,y1,x2,y2 ;          //decart's coordinates
		  float x3,y3,x4,y4 ;
   public:
		   Rectangle();                  //constructor
		  ~Rectangle();                  //destructor
		  float WriteCoord1(void);
        	  float WriteCoord2(void);
		  float WriteCoord3(void);
		  float WriteCoord4(void);

		  void  Square     (float,float);
		  float Perimeter  (float,float);
		  float Area       (float,float);
		  float Cal_Length (float,float,float,float);
		  float Cal_Width  (float,float,float,float);
		  void  PrintData  (float,float,float,float);

};

#endif
