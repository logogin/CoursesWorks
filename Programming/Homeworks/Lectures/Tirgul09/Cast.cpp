#include <iostream.h>
#include <math.h>

template <class T>
class A
{
  public:
    A(const T Val = 0)
    {
        a = Val;
    }

    A(const A<T> &rA)
    {
        a = rA.a;
    }

    operator A<T>() const
    {
        A<T1> aT1;

        unsigned S1 = sizeof(a);
        unsigned S2 = sizeof(aT1.GetA());

        if (S1 > S2)
        {
            aT1.SetA((T)(a /
                         (unsigned long)pow(2, 8 * (S1 - S2))));
        }
        else
        {
            aT1.SetA((T)(a *
                         (unsigned long)pow(2, 8 * (S1 - S2))));
        }

        return aT1;
    }
    operator A<char>() const
    {
        A<char> aT1;

        char S1 = sizeof(a);
        char S2 = sizeof(char);

        aT1.SetA((char)(a /
                        (unsigned long)pow(2, 8 * (S1 - S2))));

        return aT1;
    }
    operator A<unsigned long>() const
    {
        A<unsigned long> aT1;

        char S1 = sizeof(a);
        char S2 = sizeof(unsigned long);

        aT1.SetA((unsigned long)(a *
                                 (unsigned long)pow(2, 8 * (S1 - S2))));

        return aT1;
    }

    A<unsigned short> CastShort() const
    {
        A<unsigned short> aT1;

        short S1 = sizeof(a);
        short S2 = sizeof(unsigned short);

        if (S1 > S2)
        {
            aT1.SetA((unsigned short)(a /
                                      (unsigned long)pow(2, 8 * (S1 - S2))));
        }
        else
        {
            aT1.SetA((unsigned short)(a *
                                      (unsigned long)pow(2, 8 * (S2 - S1))));
        }

        return aT1;
    }
    A<char> CastChar() const
    {
        A<char> aT1;

        short S1 = sizeof(a);
        short S2 = sizeof(char);

        aT1.SetA((char)(a /
                        (unsigned long)pow(2, 8 * (S1 - S2))));

        return aT1;
    }
    A<unsigned long> CastLong() const
    {
        A<unsigned long> aT1;

        short S1 = sizeof(a);
        short S2 = sizeof(unsigned long);

        aT1.SetA((unsigned long)(a *
                                 (unsigned long)pow(2, 8 * (S2 - S1))));

        return aT1;
    }
    void print() const
    {
        cout << "\n"
             << (unsigned long)a
             << endl;
    }

    void SetA(T Tval)
    {
        a = Tval;
    }

    T GetA() const
    {
        return a;
    }

  private:
    T a;
};

int main(void)
{
    A<unsigned short> a1(1500);
    A<char> a2;
    A<unsigned short> a3;
    A<unsigned long> a4(78131);

    a1.print();
    a2.print();
    (a2 = a1.CastChar()).print();
    a3.print();
    (a3 = a2.CastShort()).print();
    (a3 = a1.CastShort()).print();
    a4.print();
    (a2 = a4.CastChar()).print();
    (a3 = a4.CastShort()).print();
    (a4 = a1.CastLong()).print();

    return 0;
}
