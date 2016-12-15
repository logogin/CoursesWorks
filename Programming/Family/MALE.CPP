#include "Male.h"

Male::Male(const color iSkin,const color iHair,const color iEye,const float iHigh,const float iWeight)
{
	Male::SetSkin(iSkin);
	Male::SetHair(iHair);
	Male::SetEye(iEye);
	Male::SetHigh(iHigh);
	Male::SetWeight(iWeight);
}

void Male::SetSkin(color sSkin)
{
	if (sSkin==White||sSkin==Yellow||sSkin==Red||sSkin==Black)
		m_Skin=sSkin;
} 

void Male::SetHair(color sHair)
{
	if (sHair==Blond||sHair==Brown||sHair==Red||sHair==Black)
		m_Hair=sHair;
}

void Male::SetEye(color sEye)
{
	if (sEye==Blue||sEye==Brown||sEye==Black)
		m_Eye=sEye;
}

void Male::SetHigh(float sHigh)
{
	if (sHigh>=140&&sHigh<=210)
		m_High=sHigh;
}

void Male::SetWeight(float sWeight)
{
	if (sWeight>=45&&sWeight<=130)
		m_Weight=sWeight;
}

color Male::GetSkin() const
{
	return m_Skin;
}

color Male::GetHair() const
{
	return m_Hair;
}

color Male::GetEye() const
{
	return m_Eye;
}

float Male::GetHigh() const
{
	return m_High;
} 

float Male::GetWeight() const
{
	return m_Weight;
}