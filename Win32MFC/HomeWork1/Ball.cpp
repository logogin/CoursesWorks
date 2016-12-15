// Ball.cpp: implementation of the CBall class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Single.h"
#include "Ball.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CBall,CObject,IDR_SERIAL_VERSION)

CBall::CBall():m_fRadius(0.0),m_fCenterX(0.0),m_fCenterY(0.0),m_fVelocity(0.0),
	m_fDeltaX(0.0),m_fDeltaY(0.0)
{
	m_penColor.CreatePen(PS_SOLID,0,RGB(0,0,0));
}

CBall::CBall(const FLOAT fRadius, 
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

CBall::~CBall()
{

}

void CBall::Serialize(CArchive &archive)
{
	CObject::Serialize(archive);
	LOGPEN log;
	if (archive.IsStoring())
	{
		m_penColor.GetLogPen(&log);
		archive<<m_fRadius<<m_fCenterX<<m_fCenterY<<m_fVelocity<<m_fDeltaX<<m_fDeltaY;
		archive.Write(&log,sizeof(log));
	}
	if (archive.IsLoading())
	{
		archive>>m_fRadius>>m_fCenterX>>m_fCenterY>>m_fVelocity>>m_fDeltaX>>m_fDeltaY;
		m_penColor.DeleteObject();
		archive.Read(&log,sizeof(log));
		m_penColor.CreatePenIndirect(&log);;
	}
}

CRect CBall::GetRect()
{
	CRect rect((INT)(m_fCenterX-m_fRadius),
		(INT)(m_fCenterY-m_fRadius),
		(INT)(m_fCenterX+m_fRadius),
		(INT)(m_fCenterY+m_fRadius));
	return rect;
}

FLOAT CBall::GetVelocity()
{
	return m_fVelocity;
}

BOOL CBall::Move(const CRect &rect)
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

FLOAT CBall::GetRadius()
{
	return m_fRadius;
}

FLOAT CBall::GetDeltaX()
{
	return m_fDeltaX;
}

FLOAT CBall::GetDeltaY()
{
	return m_fDeltaY;
}

CPen * CBall::GetColor()
{
	return &m_penColor;
}
