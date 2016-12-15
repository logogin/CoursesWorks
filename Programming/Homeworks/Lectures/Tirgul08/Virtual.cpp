#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

class BaseFormsClass
{
  public:
    virtual void Print() const = 0;
    virtual void Chain() const = 0;
};

class Point : public BaseFormsClass
{
  public:
    Point(const float X = 0, const float Y = 0)
    {
        m_X = X;
        m_Y = Y;
    }
    virtual void Print() const
    {
        cout << "X = "
             << m_X
             << "\tY = "
             << m_Y;
    }
    virtual void Chain() const
    {
        cout << "Point";
    }

  protected:
    float m_X;
    float m_Y;
};

/*****************************************************************************/

class Line : public Point
{
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
    virtual void Print() const
    {
        Point::Print();
        cout << "\tLENGTH = "
             << m_Length
             << "\tANGLE = "
             << m_Angle;
    }
    virtual void Chain() const
    {
        Point::Chain();
        cout << "\tLine";
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

class Triangle : public Line
{
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
    virtual void Print() const
    {
        cout << "Line1 :"
             << endl;
        m_Line1.Print();
        cout << "\nLine2 :"
             << endl;
        m_Line2.Print();
        cout << "\nLine3 :"
             << endl;
        m_Line3.Print();
        cout << "\nCONTOUR = "
             << m_Contour;
    }
    virtual void Chain() const
    {
        Line::Chain();
        cout << "\tTriangle";
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
    virtual void Print() const
    {
        Triangle::Print();
        cout << "\nCYLINDER:\tHIGH = "
             << m_High
             << "\tCONTOUR = "
             << m_Contour;
    }
    virtual void Chain() const
    {
        Triangle::Chain();
        cout << "\tCylinder";
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

    BaseFormsClass *pBase = 0;
    Point *pPoint = 0;
    Line *pLine = 0;
    Triangle *pTriangle = 0;
    Cylinder *pCylinder = 0;

    clrscr();

    /* Chaking the Point Class Using All Options. */

    pBase = &P;
    pPoint = &P;
    P.Chain();
    cout << endl;
    P.Print();
    cout << "\nB Pointer:"
         << endl;
    pBase->Chain();
    cout << endl;
    pBase->Print();
    cout << "\nP Pointer:"
         << endl;
    pPoint->Chain();
    cout << endl;
    pPoint->Print();

    /* Chaking the Line Class Using All Options. */

    cout << endl;
    pBase = &L;
    pPoint = &L;
    pLine = &L;
    L.Chain();
    cout << endl;
    L.Print();
    cout << "\nB Pointer:"
         << endl;
    pBase->Chain();
    cout << endl;
    pBase->Print();
    cout << "\nP Pointer:"
         << endl;
    pPoint->Chain();
    cout << endl;
    pPoint->Print();
    cout << "\nL Pointer:"
         << endl;
    pLine->Chain();
    cout << endl;
    pLine->Print();

    /* Chaking the Triangle Class Using All Options. */

    cout << endl;
    pBase = &T;
    pPoint = &T;
    pLine = &T;
    pTriangle = &T;
    T.Chain();
    cout << endl;
    T.Print();
    cout << "\nB Pointer:"
         << endl;
    pBase->Chain();
    cout << endl;
    pBase->Print();
    cout << "\nP Pointer:"
         << endl;
    pPoint->Chain();
    cout << endl;
    pPoint->Print();
    cout << "\nL Pointer:"
         << endl;
    pLine->Chain();
    cout << endl;
    pLine->Print();
    cout << "\nT Pointer:"
         << endl;
    pTriangle->Chain();
    cout << endl;
    pTriangle->Print();

    /* Chaking the Cylinder Class Using All Options. */

    cout << endl;
    pBase = &C;
    pPoint = &C;
    pLine = &C;
    pTriangle = &C;
    pCylinder = &C;
    C.Chain();
    cout << endl;
    C.Print();
    cout << "\nB Pointer:"
         << endl;
    pBase->Chain();
    cout << endl;
    pBase->Print();
    cout << "\nP Pointer:"
         << endl;
    pPoint->Chain();
    cout << endl;
    pPoint->Print();
    cout << "\nL Pointer:"
         << endl;
    pLine->Chain();
    cout << endl;
    pLine->Print();
    cout << "\nT Pointer:"
         << endl;
    pTriangle->Chain();
    cout << endl;
    pTriangle->Print();
    cout << "\nC Pointer:"
         << endl;
    pCylinder->Chain();
    cout << endl;
    pCylinder->Print();

    return 0;
}