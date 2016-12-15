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
    Cell &operator-=(const Cell &rCell);                  // ****
    double operator*(const Cell &rCell) const;            // ****
    Cell operator*(const double dDemo) const;             // ****
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
