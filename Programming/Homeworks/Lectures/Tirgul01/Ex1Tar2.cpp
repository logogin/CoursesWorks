/*Reading Long Number and Write it  */
/*in the Revers Order.              */

#include <iostream.h>

int main()
{
  long ReadedNumber; // Input Number Variable.
  char Bool;         // Condition for Negative Number
                     // Parameter.

  /* Reading the Number. */

  cout << "Tnsert an Integer : ";
  cin >> ReadedNumber;

  /* Chaking if the Number is Negative. */

  if (Bool = (ReadedNumber < 0))
  {
    ReadedNumber *= (-1);
  }

  /* Writing in Revers Order. */

  cout << "The Revers Number is : ";
  do
  {
    cout << (ReadedNumber % 10);
    ReadedNumber /= 10;
  } while (ReadedNumber != 0);

  /* If the Number is Negative, Writing ( - ). */

  if (Bool)
  {
    cout << "-"
         << endl;
  }
  else
  {
    cout << endl;
  }

  return 0;
} // End of Program.