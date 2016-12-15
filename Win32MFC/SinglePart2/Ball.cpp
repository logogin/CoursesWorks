// Ball.cpp : implementation file
//

#include "stdafx.h"
#include "Single.h"
#include "Ball.h"
#include ".\ball.h"


// CBall

IMPLEMENT_SERIAL(CBall, CObject,1)

CBall::CBall() :
Radius(0), CenterX(0), CenterY(0), DeltaX(0), DeltaY(0), Velocity(0)
{
}

CBall::~CBall()
{
}


// CBall member functions

void CBall::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{	// storing code
		ar << Radius << CenterX << CenterY << DeltaX << DeltaY << Velocity;
	}
	else
	{	// loading code
		ar >> Radius >> CenterX >> CenterY >> DeltaX >> DeltaY >> Velocity;
	}
}
