/*******************************************/
/*              Data Class                 */
/*******************************************/

#ifndef Data_FinalTest0199_1
#define Data_FinalTest0199_1

#include <iostream.h>

class Data
{
  private:
    int m_iData;
    Data *m_pData;

  public:
    Data(const int iData = 0)
        : m_iData(iData)
    {
        m_pData = 0;
    }

    ~Data()
    {
        if (m_pData)
        {
            delete m_pData;
        }
    }

    bool operator>(const Data &rD) const
    {
        return (m_iData > rD.m_iData);
    }

    bool operator<(const Data &rD) const
    {
        return (m_iData < rD.m_iData);
    }

    bool operator==(const Data &rD) const
    {
        return (m_iData == rD.m_iData);
    }

    /* Adding an Element After the Object. */
    /*******************************************************

        Data & operator += ( const int	iData )
        {
            Data	*	pData = m_pData			;

            m_pData = new Data ( iData )		;
            m_pData -> m_pData = pData			;

            return	*this						;
        }
*******************************************************/

    /* Adding an Element at the End of the Chain. */
    Data &operator+=(const int iData)
    {
        Data *pData = m_pData;

        if (pData)
        {
            while (pData->m_pData)
            {
                pData = pData->m_pData;
            }
            pData->m_pData = new Data(iData);
        }
        else
        {
            m_pData = new Data(iData);
        }

        return *this;
    }
    /*******************************************************/

    int GetData() const
    {
        return m_iData;
    }

    Data *GetPtr() const
    {
        return m_pData;
    }

    void SetData(const int iData)
    {
        m_iData = iData;
    }

    void SetPtr(Data *const pData)
    {
        m_pData = pData;
    }

    void PrintData() const
    {
        cout << m_iData
             << endl;
    }
};

#endif