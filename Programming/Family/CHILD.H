#ifndef Child_H
#define Child_H
#include "Male.h"
#include "Female.h"

class Child:public Male,public Female
{
	public:
		Child(const color=0,const color=0,const color=0,const float=0.0,const float=0.0,
			const color=0,const color=0,const color=0,const float=0.0,const float=0.0);
		void SetSkin(void);
		void SetHair(void);
		void SetEye(void);
		void SetHigh(void);
		void SetWeight(void);
		color GetSkin(void) const;
		color GetHair(void) const;
		color GetEye(void) const;
		float GetHigh(void) const;
		float GetWeight(void) const;
	private:
		color m_Skin;
		color m_Hair;
		color m_Eye;
		float m_High;
		float m_Weight;
};
 
#endif Child_H            