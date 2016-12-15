/*******************************************/
/*              Word Class                 */
/*******************************************/

#ifndef Word_FinalTest0199_1
#define Word_FinalTest0199_1

#include <iostream.h>
#include <string.h>

class Word
{
  private:
    char *m_szWord;

  public:
    Word(const char *szWord = 0)
    {
        m_szWord = 0;
        SetWord(szWord);
    }

    /* If the Pointer Not Zero, Free the Memory, */
    /* Allocat New Memory, and Copy the Word.    */
    void SetWord(const char *szWord = 0)
    {
        if (m_szWord)
        {
            delete[] m_szWord;
        }
        if (szWord)
        {
            m_szWord = new char[strlen(szWord) + 1];
            strcpy(m_szWord, szWord);
        }
    }

    /* Virtual to Anable Using from the Main.  */
    virtual void PrintData()
    {
        cout << m_szWord;
    }

    virtual ~Word()
    {
        /* Must not delete if m_szWord is Zero.  */
        if (m_szWord)
        {
            delete m_szWord;
        }
    }
};

#endif
