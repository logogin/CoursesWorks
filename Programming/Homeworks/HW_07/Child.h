// 10.01.2001 Dmitry Zavyalov (c)
//
// Program " Male Female Child "

#ifndef Child_H
#define Child_H
#include "male.h"
#include "female.h"

class Child: public Male, public Female
{
	private:
		int m_Skin,
			m_Hair,
			m_Eye;
		float m_High,
			  m_Weigth;

	public:
		Child();					// Constructor
		void  SetSkin( int );		// Function for set
		void  SetHair( int );		// private parametrs
		void  SetEye( int );
		void  SetHigh( float );
		void  SetWeigth( float );
		int   GetSkin( void );		// Function for read
		int   GetHair( void );		// private parametrs
		int   GetEye( void );
		float GetHigh( void );
		float GetWeigth( void );
		void  Print( void );
};
#endif
