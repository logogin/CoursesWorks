// 30.11.2000 Dmitry Zavyalov (c)
//
// 6.12 Rectangle ...

#ifndef Fi_H
#define Fi_H

class Rectangle
{
	private:
		float length;
		float width;

	public:
		Rectangle();			// Constructor by default

		void SetLength( float );
		void SetWidth( float );

		float GetLength();
		float GetWidth();

		float Perimetr();
		float Area();
};

#endif
