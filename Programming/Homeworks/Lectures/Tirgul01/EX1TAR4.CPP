/* Reading Two Different Times    */
/* and Calculate the Difference   */
/* of the Absoluts.               */

#include <iostream.h>
#include <stdlib.h>

void SetTime(short[3], char *); // Time Reading Function.

int main()
{
  short Time1[3];    // 1st Time Parameters.
  short Time2[3];    // 2nd Time Parameters.
  short DiffTime[3]; // Time Difference.
  long DiffSeconds;  // Time Difference (in seconds).

  /* Reading 1st Time Parameters  */
  /* and Chacking for Error Time. */

  SetTime(Time1,
          "1st");

  /* Reading 2nd Time Parameters  */
  /* and Chacking for Error Time. */

  SetTime(Time2,
          "2nd");

  /* Calculating the Difference in Seconds. */

  DiffSeconds = labs((long)(Time1[2] - Time2[2]) +
                     60 * (long)(Time1[1] - Time2[1]) +
                     3600 * (long)(Time1[0] - Time2[0]));

  /* Converting Seconds into hh mm ss. */

  for (int Counter = 2; Counter >= 0; Counter--)
  {
    DiffTime[Counter] = (short)(DiffSeconds % 60);
    DiffSeconds /= 60;
  }

  /* Printing the Time Difference. */

  cout << "The Time Difference : ";
  if (DiffTime[0] < 10)
  {
    cout << '0';
  }
  cout << DiffTime[0]
       << " : ";
  if (DiffTime[1] < 10)
  {
    cout << '0';
  }
  cout << DiffTime[1]
       << " : ";
  if (DiffTime[2] < 10)
  {
    cout << '0';
  }
  cout << DiffTime[2]
       << endl;

  return 0;
} // End of Program.

/* Writing the Parameter that Should be Entered,  */
/* Reading the Time from the Keybord and Chacking */
/* for Errors.                                    */

void SetTime(short TimeArr[3], char *sPtr)
{
  do
  {
    cout << "Input the "
         << sPtr
         << "Time ( hh mm ss ) :  ";
    cin >> TimeArr[0] >> TimeArr[1] >> TimeArr[2];
  } while ((TimeArr[0] < 0) || (TimeArr[0] > 23) ||
           (TimeArr[1] < 0) || (TimeArr[1] > 59) ||
           (TimeArr[2] < 0) || (TimeArr[2] > 59));
}