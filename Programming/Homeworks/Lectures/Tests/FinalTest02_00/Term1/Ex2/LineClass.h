/*******************************************/
/*              Line Class                 */
/*******************************************/

#ifndef Line_FinalTest0199_1
#define Line_FinalTest0199_1

#include "WordClass.h"

class Line : public Word
{
  private:
    Word *m_pWords;

  public:
    Line(char *const pWords = 0);

    void SetLine(char *const pWords = 0);

    virtual void PrintData();

    virtual ~Line()
    {
        /* Must not delete if m_pWords is Zero.  */
        if (m_pWords)
        {
            delete[] m_pWords;
        }
    }
};

#endif
