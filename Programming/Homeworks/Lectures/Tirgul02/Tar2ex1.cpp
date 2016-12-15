/*                         Ex2 Tar1                    */

/*******************************************************/
/*  Converting lowercase letters to uppercase letters. */
/*******************************************************/

#include <iostream.h>
#include <ctype.h>
#include <stdio.h>

/********************************************/
//          Or Use
//  #include <string.h>

void ConvertToUpperCase1(char *);
void ConvertToUpperCase2(char *);

int main(void)
{
  char String[] = "characters and $32.98";

  cout << "The string before conversion is: " << String;

  // conversion using CTYPE library.

  ConvertToUpperCase1(String);
  cout << "\nThe string after 1st conversion is: " << String;

  // conversion without using CTYPE library.

  sprintf(String, "characters and $32.98");

  /********************************************/
  //          If You Used sting.h
  //  strcpy ( String , "characters and $32.98" ) ;

  ConvertToUpperCase2(String);
  cout << "\nThe string after 2nd conversion is: " << String;

  return 0;
}

/****************************************/
/* Converting to UpperCase Using CTYPE. */
/****************************************/

void ConvertToUpperCase1(char *sPtr)
{
  while (*sPtr != '\0')
  {
    if ((*sPtr >= 'a') && (*sPtr <= 'z'))
    {
      *sPtr = toupper(*sPtr); // Convert to UpperCase.
    }
    ++sPtr;
  }
}

/************************************************/
/* Converting to Without UpperCase Using CTYPE. */
/************************************************/

void ConvertToUpperCase2(char *sPtr)
{
  char ch;

  ch = 'A' - 'a';
  while (*sPtr != '\0')
  {
    if ((*sPtr >= 'a') && (*sPtr <= 'z'))
    {
      *sPtr += ch; // Convert to UpperCase.
    }
    ++sPtr;
  }
}
