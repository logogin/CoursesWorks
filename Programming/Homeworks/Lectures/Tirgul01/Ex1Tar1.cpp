/* Reading 10 Characters From Keybord  */
/* and Write in a Tabel of Two Rows.   */
/* Writing a Char and the ASCII Value. */

#include <iostream.h>

int main()
{
  char ChArr[10]; // Array of the 10 Chars.
  int Counter;

  /* Reading the Characters. */

  cout << "Input 10 Characters : ";
  for (Counter = 0; Counter < 10; Counter++)
  {
    cin >> ChArr[Counter];
  }

  /* Printing the Characters and the ASCII. */

  for (Counter = 0; Counter < 10; Counter++)
  {
    cout << (int)ChArr[Counter]
         << " = "
         << ChArr[Counter];
    if ((Counter % 5) == 4)
    {
      cout << "\n"
           << endl;
    }
    else
    {
      cout << "   ";
    }
  }

  return 0;
} // End of Program
