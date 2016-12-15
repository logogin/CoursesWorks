#include <iostream.h>
#include <stdlib.h>
#include <math.h>

class Point
{
    friend ostream &operator<<(ostream &Output, const Point &rP);

  public:
    Point(const float X = 0, const float Y = 0)
    {
        m_X = X;
        m_Y = Y;
    }

  protected:
    float m_X;
    float m_Y;
};

/*****************************************************************************/

class Line : public Point
{
    friend ostream &operator<<(ostream &Output, const Line &rL);

  public:
    Line(const float X1 = 0, const float Y1 = 0,
         const float X2 = 0, const float Y2 = 0)
        : Point(X1, Y1)
    {
        m_Length = sqrt(pow(X1 - X2, 2) +
                        pow(Y1 - Y2, 2));
        if (m_Length)
        {
            m_Angle = atan((Y2 - Y1) /
                           (X2 - X1));
        }
        else
        {
            m_Angle = 0;
        }
    }
    float GetLength() const
    {
        return m_Length;
    }

  protected:
    float m_Length;
    float m_Angle;
};

/*****************************************************************************/

class Triangle
{
    friend ostream &operator<<(ostream &Output, const Triangle &rT);

  public:
    Triangle(const float X1 = 0, const float Y1 = 0,
             const float X2 = 0, const float Y2 = 0,
             const float X3 = 0, const float Y3 = 0)
        : m_Line1(X1, Y1, X2, Y2),
          m_Line2(X2, Y2, X3, Y3),
          m_Line3(X3, Y3, X1, Y1)
    {
        m_Contour = m_Line1.GetLength() +
                    m_Line2.GetLength() +
                    m_Line3.GetLength();
    }

  protected:
    Line m_Line1;
    Line m_Line2;
    Line m_Line3;
    float m_Contour;
};

/*****************************************************************************/

class Cylinder : public Triangle
{
    friend ostream &operator<<(ostream &Output, const Cylinder &rC);

  public:
    Cylinder(const float X1 = 0, const float Y1 = 0,
             const float X2 = 0, const float Y2 = 0,
             const float X3 = 0, const float Y3 = 0,
             const float h = 0)
        : Triangle(X1, Y1, X2, Y2, X3, Y3)
    {
        m_High = h;
        m_Contour = 3 * m_High +
                    2 * Triangle::m_Contour;
    }

  protected:
    float m_High;
    float m_Contour;
};

/*****************************************************************************/

int main(void)
{
    Point P(5, 3);
    Line L(6, 2, 8, 0);
    Triangle T(1, 2, 3, 4, 5, 6);
    Cylinder C(0, 0, 8, 9, 2, 4, 8);

    cout << "Point\t\t"
         << P
         << "Line\t\t"
         << L
         << "Triangle\t"
         << T
         << "Cylinder\t"
         << C
         << endl;

    return 0;
}