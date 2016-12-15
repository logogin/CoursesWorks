// Exam 1 03.10.2000 - Ex. No. 2
// Relation Class Definition
#ifndef ALL_CLASSES
#define ALL_CLASSES
#include <stdlib.h>
#include <math.h>

// 1 Dimentional Point
class Point1D
{
  public:
    Point1D(const float fX1 = 0.0)
        : m_fX1(fX1)
    {
    }
    float operator-(const Point1D &refP1D) const
    {
        return (float)fabs(m_fX1 - refP1D.m_fX1);
    }

  protected:
    float m_fX1;
};
;

// 2 Dimentional Point
class Point2D : public Point1D
{
  public:
    Point2D(const float fX1 = 0.0, const float fX2 = 0.0)
        : Point1D(fX1),
          m_fX2(fX2)
    {
    }
    float operator-(const Point2D &refP2D) const
    {
        return (float)sqrt((m_fX1 - refP2D.m_fX1) * (m_fX1 - refP2D.m_fX1) +
                           (m_fX2 - refP2D.m_fX2) * (m_fX2 - refP2D.m_fX2));
    }

  protected:
    float m_fX2;
};
;

// 1 Dimentional Elips
class Elips1D
{
  public:
    Elips1D(const float fRadius = 0.0, const float fX1 = 0.0, const float fY1 = 0.0);
    float GetRadius() const
    {
        return m_fRadius;
    }
    virtual float CenterDistance() const;
    ;

  protected:
    float m_fRadius;

  private:
    Point1D m_X;
    Point1D m_Y;
};

// 2 Dimentional Elips
class Elips2D : public Elips1D
{
  public:
    Elips2D(const float fRadius = 0.0, const float fX1 = 0.0, const float fX2 = 0.0,
            const float fY1 = 0.0, const float fY2 = 0.0);
    virtual float CenterDistance() const;

  private:
    Point2D m_X;
    Point2D m_Y;
};
#endif
