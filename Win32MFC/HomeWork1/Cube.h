// Cube.h: interface for the CCube class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CUBE_H__E8FCA89B_1042_4B76_B1E0_44089127EBBC__INCLUDED_)
#define AFX_CUBE_H__E8FCA89B_1042_4B76_B1E0_44089127EBBC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCube : public CObject  
{
public:
	CPen * GetColor();
	FLOAT GetDeltaY(void);
	FLOAT GetDeltaX(void);
	FLOAT GetRadius(void);
	BOOL Move(const CRect &rect);
	FLOAT GetVelocity(void);
	CRect GetRect(void);
	CCube(const FLOAT fRadius, 
		const FLOAT fCenterX,
		const FLOAT fCenterY,
		const FLOAT fVelocity,
		const FLOAT fDeltaX,
		const FLOAT fDeltaY,
		CPen &penColor);
	virtual void Serialize(CArchive &archive);
	CCube();
	virtual ~CCube();

	DECLARE_SERIAL(CCube)
protected:
	CPen m_penColor;
	FLOAT m_fDeltaY;
	FLOAT m_fDeltaX;
	FLOAT m_fVelocity;
	FLOAT m_fCenterY;
	FLOAT m_fCenterX;
	FLOAT m_fRadius;
};

#endif // !defined(AFX_CUBE_H__E8FCA89B_1042_4B76_B1E0_44089127EBBC__INCLUDED_)
