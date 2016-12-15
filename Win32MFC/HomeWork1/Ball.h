// Ball.h: interface for the CBall class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BALL_H__CD757A26_B1B3_47F2_9281_2AA73BFFA55C__INCLUDED_)
#define AFX_BALL_H__CD757A26_B1B3_47F2_9281_2AA73BFFA55C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CBall : public CObject  
{
public:
	CPen * GetColor(void);
	FLOAT GetDeltaY(void);
	FLOAT GetDeltaX(void);
	FLOAT GetRadius(void);
	BOOL Move(const CRect &rect);
	FLOAT GetVelocity(void);
	CRect GetRect(void);
	CBall(const FLOAT fRadius, 
		const FLOAT fCenterX,
		const FLOAT fCenterY,
		const FLOAT fVelocity,
		const FLOAT fDeltaX,
		const FLOAT fDeltaY,
		CPen &penColor);
	virtual void Serialize(CArchive &archive);
	CBall();
	virtual ~CBall();

	DECLARE_SERIAL(CBall)
protected:
	CPen m_penColor;
	FLOAT m_fDeltaY;
	FLOAT m_fDeltaX;
	FLOAT m_fVelocity;
	FLOAT m_fCenterY;
	FLOAT m_fCenterX;
	FLOAT m_fRadius;
};

#endif // !defined(AFX_BALL_H__CD757A26_B1B3_47F2_9281_2AA73BFFA55C__INCLUDED_)
