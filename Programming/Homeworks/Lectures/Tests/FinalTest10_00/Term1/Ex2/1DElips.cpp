#include <stdlib.h>
#include <math.h>
#include "Classes.h"

Elips1D::Elips1D(const float fRadius, const float fX1, const float fY1)
    : m_fRadius(fRadius),
      m_X(fX1),
      m_Y(fY1)
{
    float fDist;

    if ((fDist = m_X - m_Y) > m_fRadius)
    {
        m_fRadius = 2 * fDist;
    }
}

float Elips1D::CenterDistance() const
{
    return (m_X - m_Y);
}
