#include <iostream.h>
#include <conio.h>

template <class T, int usElements>
class MyArray
{
  public:
    MyArray(){};
    void PrintArray() const
        private : T m_ArrT[usElements];
};

template <class T, int usElements>
void MyArray<T, usElements>::PrintArray() const
{
    for (int i = 0; i < usElements; i++)
        cout << m_ArrT[i] << endl;
}

main()
{
    MyArray<float, 5> IntArr;
    MyArray::PrintArray();
    return 0;
}
