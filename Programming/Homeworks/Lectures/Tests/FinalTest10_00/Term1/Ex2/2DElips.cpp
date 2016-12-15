#include <stdlib.h>
#include <math.h>
#include "Classes.h"

Elips2D::Elips2D(const float fRadius, const float fX1, const float fX2,
                 const float fY1, const float fY2)
    : Elips1D(fRadius),
      m_X(fX1, fX2),
      m_Y(fY1, fY2)
{
    float fDist;

    if ((fDist = m_X - m_Y) > m_fRadius)
    {
        m_fRadius = 2 * fDist;
    }
}

float Elips2D::CenterDistance() const
{
    return (m_X - m_Y);
}
