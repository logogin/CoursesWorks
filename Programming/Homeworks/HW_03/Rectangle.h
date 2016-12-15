// 08.12.2000 Dmitry Zavyalov (c)
//
// 6.13 Subtle Rectangle ...

#ifndef Fi_H
#define Fi_H

class Rectangle
{
	private:
		float	x1, y1,			// Decard's coordinates
				x2, y2,
				x3, y3,
				x4, y4;


	public:
		Rectangle();			// Constructor by default

		void SetVertex(int);

		float Length(void);
		float Width(void);
		float Perimetr(void);
		float Area(void);

		int Square(void);

		void RecInf(void);
		void Error(int);
};

#endif
