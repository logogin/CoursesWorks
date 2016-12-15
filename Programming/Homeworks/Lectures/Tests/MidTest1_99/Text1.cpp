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

/************************************************************************/

#include "Cell.h"

double Cell::s_dLearningRate = 0.99;

Cell::Cell(const Cell &rCell) // ****
{
    m_usCellsSize = rCell.m_usCellsSize;
    if (m_usCellsSize)
    {
	m_pdCell = new double[m_usCellsSize];
	memcpy(m_pdCell,
	       rCell.m_pdCell,
	       m_usCellsSize * sizeof(double));
    }
}

double Cell::Distance(const double *const pdInVector)
{
    return (*this - pdInVector) * (*this - pdInVector);
}

void Cell::TrainCell(const double *const pdInVector)
{
    *this -= (*this - pdInVector) * s_dLearningRate;
    s_dLearningRate *= 0.9;
}

Cell Cell::operator-(const double *const pdInVector) const
{
    unsigned short usCounter = 0;
    Cell TempCell(*this);

    for (; usCounter < m_usCellsSize; usCounter++)
    {
	TempCell.m_pdCell[usCounter] -= pdInVector[usCounter];
    }

    return TempCell;
}

Cell &Cell::operator-=(const Cell &rCell)
{
    unsigned short usCounter = 0;

    for (; usCounter < m_usCellsSize; usCounter++)
    {
	m_pdCell[usCounter] -= rCell.m_pdCell[usCounter];
    }

    return *this;
}

double Cell::operator*(const Cell &rCell) const
{
    unsigned short usCounter = 0;
    double TempResult = 0.0;

    for (; usCounter < m_usCellsSize; usCounter++)
    {
	TempResult += m_pdCell[usCounter] *
		      rCell.m_pdCell[usCounter];
    }

    return TempResult;
}

Cell Cell::operator*(const double dDemo) const
//Cell Cell :: operator * (  ) const
{
    unsigned short usCounter = 0;
    Cell TempCell(*this);

    for (; usCounter < m_usCellsSize; usCounter++)
    {
	TempCell.m_pdCell[usCounter] *= dDemo;
    }

    return TempCell;
}

void Cell::HelpInit()
{
    if (m_usCellsSize)
    {
	unsigned short usCounter = 0;

	m_pdCell = new double[m_usCellsSize];
	for (; usCounter < m_usCellsSize; usCounter++)
	{
	    m_pdCell[usCounter] *= (double)rand() /
				       RAND_MAX -
				   0.5;
	}
    }
}

/************************************************************************/

#ifndef SE_MID_TEST_SEMESTER1_1999_A
#define SE_MID_TEST_SEMESTER1_1999_A

#include <stdlib.h>
#include <iostream.h>
#include <assert.h>
#include <memory.h>

class Cell
{
  public:
    Cell(const unsigned short usCellsSize = 0)
    {
	m_usCellsSize = usCellsSize;
	HelpInit();
    }
    Cell(const Cell &rCell); // ****

    void InitCell(const unsigned short usCellsSize) // ****
    {
	if (m_usCellsSize != 0)
	{
	    delete[] m_pdCell;
	}

	m_usCellsSize = usCellsSize;
	HelpInit();
    }

    double Distance(const double *const pdInVector);
    void TrainCell(const double *const pdInVector);
    Cell operator-(const double *const pdInVector) const; // ****
    Cell &operator-=(const Cell &rCell);		  // ****
    double operator*(const Cell &rCell) const;		  // ****
    Cell operator*(const double dDemo) const;		  // ****
    ~Cell()
    {
	if (m_usCellsSize)
	{
	    delete[] m_pdCell;
	}
    }

  private:
    unsigned short m_usCellsSize;
    double *m_pdCell;
    static double s_dLearningRate;
    void HelpInit();
};

#endif
