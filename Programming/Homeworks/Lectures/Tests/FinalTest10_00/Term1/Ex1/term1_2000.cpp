#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include "relation.h"

int main(void)
{
    ppBool pBool1;
    ppBool pBool2;
    pBool1 = new bool *[2];
    pBool1[0] = new bool[6];
    pBool1[1] = pBool1[0] + 3;
    pBool1[0][0] = pBool1[0][1] = pBool1[1][1] = 0;
    pBool1[0][2] = pBool1[1][0] = pBool1[1][2] = 1;
    pBool2 = new bool *[2];
    pBool2[0] = new bool[6];
    pBool2[1] = pBool2[0] + 3;
    pBool2[0][1] = pBool2[1][0] = pBool2[1][1] = pBool2[0][2] = 0;
    pBool2[0][0] = pBool2[1][2] = 1;
    Relation R1(2, 3, pBool1);
    Relation R2(2, 3, pBool2);

    cout << R1
         << R2;
    cout << (!R1.SetRelation(R2));

    ofstream OutFile("Test.txt", ios::out);
    R1 += R2;
    OutFile << R1
            << !R2;
    R1.Write("Test.tst");

    delete[] * pBool1;
    delete[] pBool1;
    delete[] * pBool2;
    delete[] pBool2;

    return 0;
}
