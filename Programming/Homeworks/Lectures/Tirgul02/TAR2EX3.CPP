/*                  Ex2Tar3              */

/*****************************************/
/*  Reading a Streang From Keybord, Copy */
/*  it All to Another String and Only    */
/*  15 Letters to Additional String.     */
/*****************************************/

#include <iostream.h>
#include <string.h>

int main(void)
{
  char MainString[256];
  char SecondString[256];
  char LastString[15];

  cout << "Input a String :\n";
  cin.getline(MainString, 256, '\n'); // Reading String Untill the
                                      // Enter or 256 Characters.

  cout << "The Main String is: "
       << MainString
       << "\nThe Second String is :"
       << strcpy(SecondString, MainString)
       << endl;
  strncpy(LastString, MainString, 14);
  LastString[14] = '\0';
  cout << "\nThe Last String is: "
       << LastString
       << endl;

  return 0;
}
