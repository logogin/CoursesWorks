/*******************************************/
/*              Page Class                 */
/*******************************************/

#ifndef Page_FinalTest0199_1
#define Page_FinalTest0199_1

#include "LineClass.h"

class Page : public Line
{
  private:
    Line *m_pLines;

  public:
    Page(char *const pWords = 0);

    virtual void PrintData();

    virtual ~Page()
    {
        /* Must not delete if m_pLines is Zero.  */
        if (m_pLines)
        {
            delete[] m_pLines;
        }
    }
};

#endif
