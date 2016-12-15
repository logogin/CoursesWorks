// 10.01.2001 Dmitry Zavyalov (c)
//
// Program " Male Female Child "

#ifndef Male_H
#define Male_H

class Male
{
	protected:
		int m_Skin,
			m_Hair,
			m_Eye;
		float m_High,
			  m_Weigth;

	public:
		Male();					// Constructor
		void  SetSkin( int );	// Function for set
		void  SetHair( int );	// protected parametrs
		void  SetEye( int );
		void  SetHigh( float );
		void  SetWeigth( float );
		int   GetSkin( void );	// Function for read
		int   GetHair( void );	// protected parametrs
		int   GetEye( void );
		float GetHigh( void );
		float GetWeigth( void );
};
#endif
