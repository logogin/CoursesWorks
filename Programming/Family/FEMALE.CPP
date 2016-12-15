#include "Female.h"

enum {White,Yellow,Red,Black,Brown,Blue,Blond};
Female::Female(const color iSkin,const color iHair,const color iEye,const float iHigh,const float iWeight)
{
	Female::SetSkin(iSkin);
	Female::SetHair(iHair);
	Female::SetEye(iEye);
	Female::SetHigh(iHigh);
	Female::SetWeight(iWeight);
}

void Female::SetSkin(color sSkin)
{
	if (sSkin==White||sSkin==Yellow||sSkin==Red||sSkin==Black)
		m_Skin=sSkin;
} 

void Female::SetHair(color sHair)
{
	if (sHair==Blond||sHair==Brown||sHair==Red||sHair==Black)
		m_Hair=sHair;
}

void Female::SetEye(color sEye)
{
	if (sEye==Blue||sEye==Brown||sEye==Black)
		m_Eye=sEye;
}

void Female::SetHigh(float sHigh)
{
	if (sHigh>=140&&sHigh<=210)
		m_High=sHigh;
}

void Female::SetWeight(float sWeight)
{
	if (sWeight>=45&&sWeight<=130)
		m_Weight=sWeight;
}

color Female::GetSkin() const
{
	return m_Skin;
}

color Female::GetHair() const
{
	return m_Hair;
}

color Female::GetEye() const
{
	return m_Eye;
}

float Female::GetHigh() const
{
	return m_High;
} 

float Female::GetWeight() const
{
	return m_Weight;
}