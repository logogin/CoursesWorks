// Problem 8.39,p.361, from "C: How To Program", by H.M.Deitel & P.J.Deitel
// Morse code was developed by Samuel Morse in 1832 for use with the
// telegraph system. The Morse code assignes a series of dots and dashes
// to each letter of the alphabet, each digit and a few special characters.
// (such as period, comma, colon and semicolon). Below you can see the
// international version of the Morse code (special characters are omitted).
// Write a program that reads an English language phrase and encodes the
// phrase into Morse code. Use one blank between each Morse-coded letter
// and three blanks between each Morse-coded word

// Solution, version 1: Author: Dr. N.Garber.
// Assumed, that in input string the legal characters are:
// digits, lowercase letters, and SPACE's.
// Solution: if any other character occurs in input string, it is ignored,
// and the next character processing (translating) is carried out
// It is useful to know ( "C: How To Program", p.891 ) ASCII codes
// for some characters: for '0' is 48, for 'a' is 97, for 'A' is 65.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void encode (char *, char **);
main()  {
//                   0         1         2         3         4
char *morse[36]={ "-----",  ".----",  "..---",  "...--",  "....-",
//                   5         6         7         8         9
		  ".....",  "-....",  "--...",  "---..",  "----.",
//                  a       b        c      d      e        f       g
		  ".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
//                  h       i        j      k      l        m       n
		  "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
//                  o       p        q      r       s      t        u
		  "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
//                  v       w       x       y       z
		  "...-", ".--",  "-..-", "-.--", "--.."  };

char English_Text[255];
   clrscr();
   gets(English_Text);
   encode(English_Text, morse);
return 0;
}

void encode (char *let, char **morse)  {
int i;
   for (i=0; let[i] !='\0'; i++) {
	 if ( isdigit(let[i]) )
	 //  printing Morse code of a digit
			 printf("%s",morse[ (int)let[i]-48 ]);
	   else  if ( islower(let[i]) )
	 //  printing Morse code of a lowercase letter
					printf("%s",morse[ (int)let[i]-87 ]);
			   else if ( let[i] == ' ' )
	 // printing two SPACE's as a separator between the Morse-coded words
					  printf("  ");
	 // in other cases, printing error message
	 printf(" ");       // appending SPACE after each Morse-coded letter
   }
}