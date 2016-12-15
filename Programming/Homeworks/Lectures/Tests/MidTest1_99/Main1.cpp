#include <stdlib.h>
#include <iostream.h>
#include "Cell.h"

int main(void)
{
    unsigned short usCellsNumber;
    unsigned short usCellsSize;
    unsigned short usInputVectorsNumber;
    double **ppdData;
    Cell *pCells;

    cout << "Input the Numper of Cells: ";
    cin >> usCellsNumber;
    cout << "Input Cells Size: ";
    cin >> usCellsSize;
    cout << "How Many Input Vectors Do You Have? ";
    cin >> usInputVectorsNumber;

    if (usInputVectorsNumber > 0)
    {
        unsigned short usCounter = 0;
        unsigned short usTempSize;

        usTempSize = usInputVectorsNumber *
                     usCellsSize;
        ppdData = new double *[usInputVectorsNumber];
        ppdData[0] = new double[usTempSize];

        for (; usCounter < usTempSize; usCounter++)
        {
            cout << "Input a New Value: ";
            cin >> ppdData[0][usCounter];
        }

        for (usCounter = 1;
             usCounter < usInputVectorsNumber;
             usCounter++)
        {
            ppdData[usCounter] =
                &ppdData[usCounter - 1]
                        [usCellsSize];
        }

        pCells = new Cell[usCellsNumber]; // ***
        for (usCounter = 0;
             usCounter < usInputVectorsNumber;
             usCounter++)
        {
            pCells[usCounter].InitCell(usCellsSize);
        }

        for (usCounter = 0;
             usCounter < usInputVectorsNumber;
             usCounter++)
        {
            double dMinDistance;
            unsigned short usMinArgument = 0;
            unsigned short usInCounter = 1;

            dMinDistance = pCells[0].Distance(ppdData[usCounter]);

            for (; usInCounter < usCellsNumber;
                 usInCounter++)
            {
                double dTmpDist;

                dTmpDist = pCells[usInCounter].Distance(ppdData[usCounter]);

                if (dTmpDist < dMinDistance)
                {
                    dMinDistance = dTmpDist;
                    usMinArgument = usInCounter;
                }
            }

            pCells[usMinArgument].TrainCell(ppdData[usCounter]);
        }
    }

    return 0;
}