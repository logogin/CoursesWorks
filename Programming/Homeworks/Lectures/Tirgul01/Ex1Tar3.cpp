/*Reading Two Numbers and Write   */
/*a Matrix of All Multiplecations */
/*From 1 to the 1st Number By     */
/*1 to to the 2nd Number.         */

#include <iostream.h>
#include <iomanip.h> // Manipulators Difinitions File.

int MatrixSize[2]; // Parameters of the Matrix.
void MatrixSizes();
void PrintMultiplicationBoard();

int main()
{

  /* Reading the Matrix Size */

  MatrixSizes();

  /* Printin the Multiplexing Matrix */
  /* on the Screen.                  */

  cout << "Printing the Matrix :"
       << endl;
  PrintMultiplicationBoard();

  return 0;
} // End of Program.

/* Reading the Matrix Size */
/* and Testing for Errors  */
/* ( Size <= 0, is Wrong). */

void MatrixSizes()
{
  do
  {
    cout << "Input Positive 2 Integers : ";
    cin >> MatrixSize[0] >> MatrixSize[1];
  } while ((MatrixSize[0] <= 0) ||
           (MatrixSize[1] <= 0));
}

/* Printing the Multiplication Board. */

void PrintMultiplicationBoard()
{
  int Counters[2]; // Two Counters.

  for (Counters[0] = 1;
       Counters[0] <= MatrixSize[0];
       Counters[0]++)
  {
    for (Counters[1] = 1;
         Counters[1] <= MatrixSize[1];
         Counters[1]++)
    {
      cout << setw(5)
           << (Counters[0] *
               Counters[1]);
    }
    cout << endl;
  }
}
