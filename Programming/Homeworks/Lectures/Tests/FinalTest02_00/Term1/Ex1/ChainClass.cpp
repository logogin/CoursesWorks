/***********************************************/
/*         Chain Class Functions               */
/***********************************************/

#include "DataClass.h"
#include "ChainClass.h"

Chain &Chain::operator+=(const Data &rD)
{
    Data *pD = 0;

    /* If the New Object Less Than the First, */
    /* Put It in the Beginning of the Chain.  */
    if (*m_pHelpChain > rD)
    {
        m_pHelpChain = new Data(rD.GetData());
        m_pHelpChain->SetPtr(m_pChain);
        m_pChain = m_pHelpChain;
        return *this;
    }

    /* Else Look for a Place in the Chain,  */
    /* and Insert the Object.               */
    while (*m_pHelpChain < rD)
    {
        if (m_pHelpChain->GetPtr())
        {
            pD = m_pHelpChain;
            m_pHelpChain = m_pHelpChain->GetPtr();
        }
        else
        {
            *m_pHelpChain += rD.GetData();
            m_pHelpChain = m_pChain;

            return *this;
        }
    }

    /* If the New Object is the Biggest One, */
    /* Place It in the End of the Chain.     */

    pD = new Data(rD.GetData());
    pD->SetPtr(m_pHelpChain);
    m_pHelpChain = m_pChain;

    return *this;
}

Chain &Chain::operator~()
{
    short sCount = 0;
    short sChainLength = 0;

    int *pInt = 0;

    /* Find the Number od Element in the Chain. */
    while (m_pHelpChain)
    {
        m_pHelpChain = m_pHelpChain->GetPtr();
        sChainLength++;
    }

    /* Allocat a Memory for All the Numbers. */
    m_pHelpChain = m_pChain;
    pInt = new int[sChainLength];

    /* Copy the Numbers from the Chain to the Array. */
    for (; sCount < sChainLength; sCount++)
    {
        pInt[sCount] = m_pHelpChain->GetData();
        m_pHelpChain = m_pHelpChain->GetPtr();
    }

    m_pHelpChain = m_pChain;

    /* Copy the Numbers from Array to the Chain in the Revers Order. */
    for (--sCount; sCount >= 0; sCount--)
    {
        m_pHelpChain->SetData(pInt[sCount]);
        m_pHelpChain = m_pHelpChain->GetPtr();
    }

    m_pHelpChain = m_pChain;
    delete[] pInt;

    return *this;
}

void Chain::PrintChain() const
{
    Data *pD = m_pChain;
    while (pD)
    {
        pD->PrintData();
        pD = pD->GetPtr();
    }
}