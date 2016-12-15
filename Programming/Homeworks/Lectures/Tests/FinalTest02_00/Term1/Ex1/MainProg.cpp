/***********************************************/
/*                  Main Program               */
/***********************************************/

#include <iostream.h>
#include "DataClass.h"
#include "ChainClass.h"

int main(void)
{
    Chain NewChain(-3);
    unsigned short usTest;

    do
    {
        cout << "If you want to add to chain press 0: ";
        cin >> usTest;

        /*  If usTest = 0, Add an Object to the Chain */
        /*  In Increasing Order (Look Operator +=).   */
        if (!usTest)
        {
            int iNewNum;

            cout << "Input New Number: ";
            cin >> iNewNum;

            NewChain += Data(iNewNum);
        }
    } while (!usTest);

    NewChain.PrintChain();

    /*  Invers Chains Order.  */
    ~NewChain;
    NewChain.PrintChain();

    return 0;
}