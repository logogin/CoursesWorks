/*                  x2 Tar2             */

/****************************************/
/*  Three Functions Calling Using       */
/*  Array of Functions Pointers.        */
/****************************************/

#include <iostream.h>

void function0(int);
void function1(int);
void function2(int);

int main(void)
{
  void (*f[3])(int) = {function0,  // The tree function that can be cald
                       function1,  // initialized in the array to functions
                       function2}; // pointers.
  int FunctionsChoice;

  do
  {
    FunctionsChoice = -1; // Enabeled the Enterence to the While
                          // After 0 <= FunctionsChoice < 3.

    /************************************/
    /* Reading FunctionsChoice Until it */
    /* Between 0 and 3.                 */
    /************************************/

    while ((FunctionsChoice < 0) || (FunctionsChoice > 3))
    {
      cout << "Enter the Number of between 0 and 2, or 3 for Exit: ";
      cin >> FunctionsChoice;
    }
    /************************************/
    /* FunctionsChoice Between 0 and 2  */
    /* Call to Function.                */
    /************************************/

    if (FunctionsChoice != 3)
    {
      (*f[FunctionsChoice])(FunctionsChoice);
    }
  } while (FunctionsChoice != 3);

  cout << "End of Program."
       << endl;

  return 0;
}

void function0(int FuncNum)
{
  cout << "You Entered "
       << FuncNum
       << " So function0 was Cald."
       << endl;
}

void function1(int FuncNum)
{
  cout << "You Entered "
       << FuncNum
       << " So function1 was Cald."
       << endl;
}

void function2(int FuncNum)
{
  cout << "You Entered "
       << FuncNum
       << " So function2 was Cald."
       << endl;
}
