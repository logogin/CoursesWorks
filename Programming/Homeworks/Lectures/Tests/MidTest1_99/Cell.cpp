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
