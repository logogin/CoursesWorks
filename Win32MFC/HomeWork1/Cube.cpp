// Cube.cpp: implementation of the CCube class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Single.h"
#include "Cube.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_SERIAL(CCube,CObject,IDR_SERIAL_VERSION)

CCube::CCube():m_fRadius(0.0),m_fCenterX(0.0),m_fCenterY(0.0),m_fVelocity(0.0),
	m_fDeltaX(0.0),m_fDeltaY(0.0)
{
	m_penColor.CreatePen(PS_SOLID,0,RGB(0,0,0));
}

CCube::CCube(const FLOAT fRadius, 
			 const FLOAT fCenterX,
			 const FLOAT fCenterY,
			 const FLOAT fVelocity,
			 const FLOAT fDeltaX,
			 const FLOAT fDeltaY,
			 CPen &penColor)
			 :m_fRadius(fRadius),m_fCenterX(fCenterX), m_fCenterY(fCenterY),
			 m_fVelocity(fVelocity),m_fDeltaX(fDeltaX),m_fDeltaY(fDeltaY)
{
	LOGPEN log;
	penColor.GetLogPen(&log);
	m_penColor.CreatePenIndirect(&log);
}

CCube::~CCube()
{

}

void CCube::Serialize(CArchive &archive)
{
	CObject::Serialize(archive);
	m_penColor.Serialize(archive);
	if (archive.IsStoring())
		archive<<m_fRadius<<m_fCenterX<<m_fCenterY<<m_fVelocity<<m_fDeltaX<<m_fDeltaY;
	if (archive.IsLoading())
		archive>>m_fRadius>>m_fCenterX>>m_fCenterY>>m_fVelocity>>m_fDeltaX>>m_fDeltaY;
}

CRect CCube::GetRect()
{
	CRect rect((INT)(m_fCenterX-m_fRadius),
		(INT)(m_fCenterY-m_fRadius),
		(INT)(m_fCenterX+m_fRadius),
		(INT)(m_fCenterY+m_fRadius));
	return rect;
}

FLOAT CCube::GetVelocity()
{
	return m_fVelocity;
}

BOOL CCube::Move(const CRect &rect)
{
	BOOL bInRect=TRUE;
	m_fCenterX+=m_fDeltaX;
	m_fCenterY+=m_fDeltaY;
	if ((m_fCenterX+m_fRadius+m_fDeltaX)>rect.right||
		(m_fCenterX-m_fRadius+m_fDeltaX)<rect.left)
	{
		m_fDeltaX=-m_fDeltaX;
		bInRect=FALSE;
	}
	if ((m_fCenterY+m_fRadius+m_fDeltaY)>rect.bottom||
		(m_fCenterY-m_fRadius+m_fDeltaY)<rect.top)
	{
		m_fDeltaY=-m_fDeltaY;
		bInRect=FALSE;
	}

	return bInRect;
}

FLOAT CCube::GetRadius()
{
	return m_fRadius;
}

FLOAT CCube::GetDeltaX()
{
	return m_fDeltaX;
}

FLOAT CCube::GetDeltaY()
{
	return m_fDeltaY;
}

CPen * CCube::GetColor()
{
	return &m_penColor;
}
