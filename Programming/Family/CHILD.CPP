#include "Child.h"
#include <time.h>
#include <stdlib.h>

Child::Child(const color miSkin,const color miHair,const color miEye,
			 const float miHigh,const float miWeight,
			 const color fiSkin,const color fiHair,const color fiEye,
			 const float fiHigh,const float fiWeight)
			 :Male(miSkin,miHair,miEye,miHigh,miWeight),
			 Female(fiSkin,fiHair,fiEye,fiHigh,fiWeight)
{
	srand((unsigned)time(NULL));
	Child::SetSkin();
	Child::SetHair();
	Child::SetEye();
	Child::SetHigh();
	Child::SetWeight();
}

void Child::SetSkin()
{
	const colors[4]={White,Yellow,Red,Black};
	float p=(float)(rand()%100)/100;
	if (p<=0.1)
		m_Skin=colors[rand()%4];
	if (p>0.1&&p<=0.2)
		m_Skin=Male::GetSkin();
	if (p>0.2&&p<=0.3)
		m_Skin=Female::GetSkin();
	if (p>0.3&&p<=0.5)
		m_Skin=Male::GetSkin()>=Female::GetSkin() ? Female::GetSkin() : Male::GetSkin();
	if (p>0.5)
		m_Skin=Male::GetSkin()>=Female::GetSkin() ? Male::GetSkin() : Female::GetSkin();
} 

void Child::SetHair()
{
	const colors[4]={Blond,Red,Black,Brown};
	float p=(float)(rand()%100)/100;
	if (p<=0.1)
		m_Hair=colors[rand()%4];
	if (p>0.1&&p<=0.2)
		m_Hair=Male::GetHair();
	if (p>0.2&&p<=0.3)
		m_Hair=Female::GetHair();
	if (p>0.3&&p<=0.5)
		m_Hair=Male::GetHair()>=Female::GetHair() ? Female::GetHair() : Male::GetSkin();
	if (p>0.5)
		m_Hair=Male::GetHair()>=Female::GetHair() ? Male::GetHair() : Female::GetSkin();
}

void Child::SetEye()
{
	const colors[3]={Blue,Brown,Black};
	float p=(float)(rand()%100)/100;
	if (p<=0.1)
		m_Eye=colors[rand()%3];
	if (p>0.1&&p<=0.2)
		m_Eye=Male::GetEye();
	if (p>0.2&&p<=0.3)
		m_Eye=Female::GetEye();
	if (p>0.3&&p<=0.5)
		m_Eye=Male::GetEye()>=Female::GetEye() ? Female::GetEye() : Male::GetSkin();
	if (p>0.5)
		m_Eye=Male::GetEye()>=Female::GetEye() ? Male::GetEye() : Female::GetSkin();
}

void Child::SetHigh()
{
	m_High=((Male::GetHigh()+Female::GetHigh())/2)+10.0;
}

void Child::SetWeight()
{
	m_Weight=((Male::GetWeight()+Female::GetWeight())/2)*1.05;
}

color Child::GetSkin() const
{
	return m_Skin;
}

color Child::GetHair() const
{
	return m_Hair;
}

color Child::GetEye() const
{
	return m_Eye;
}

float Child::GetHigh() const
{
	return m_High;
} 

float Child::GetWeight() const
{
	return m_Weight;
}