/********************************************/
/*                Chain Class               */
/********************************************/

#ifndef Chain_FinalTest0199_1
#define Chain_FinalTest0199_1

#include "DataClass.h"

class Chain
{
  private:
    Data *m_pChain;
    Data *m_pHelpChain;

  public:
    Chain(const int iData = 0)
    {
        m_pChain = new Data(iData);
        m_pHelpChain = m_pChain;
    }

    ~Chain()
    {
        m_pHelpChain = 0;
        delete m_pChain;
    }

    Chain &operator+=(const Data &rD);

    Chain &operator~();

    void PrintChain() const;
};

#endif