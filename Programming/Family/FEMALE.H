
#ifndef Female_H
#define Female_H

typedef unsigned char color;

class Female
{
	public:
		Female(const color=0,const color=0,const color=0,const float=0.0,const float=0.0);
		void SetSkin(const color);
		void SetHair(const color);
		void SetEye(const color);
		void SetHigh(const float);
		void SetWeight(const float);
		color GetSkin(void) const;
		color GetHair(void) const;
		color GetEye(void) const;
		float GetHigh(void) const;
		float GetWeight(void) const;
	protected:
		color m_Skin;
		color m_Hair;
		color m_Eye;
		float m_High;
		float m_Weight;
};
 
#endif Female_H