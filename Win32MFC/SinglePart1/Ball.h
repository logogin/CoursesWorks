#pragma once



// CBall command target

class CBall : public CObject
{
public:
	CBall();
	virtual ~CBall();
	int Radius;
	float CenterX, CenterY, DeltaX, DeltaY, Velocity;
};


