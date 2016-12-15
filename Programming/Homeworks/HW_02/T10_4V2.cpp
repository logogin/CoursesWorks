// Problem 8.39,p.361, from "C: How To Program", by H.M.Deitel & P.J.Deitel
// Solution, version 2: Author: Dr. N.Garber.
// Assumed, that in input string the legal characters are:
// digits, lowercase letters, uppercase letters and SPACE's.
// Solution: if uppercase letter occurs in input string,
// it gets the same Morse code as its corresponded lowercase letter.
// If any other character occurs in input string, message error is printed
// on its place, and the next character processing is carried out.
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
	   else if ( isupper(let[i]) )
	 //  printing Morse code of an uppercase letter
		printf("%s",morse[ (int)let[i]-55 ]);
				   else if ( let[i] == ' ' )
	 // printing two SPACE's as a separator between the Morse-coded words
								printf("  ");
	 // in other cases, printing error message
						  else  printf("error");

	 printf(" ");        // appending SPACE after each Morse-coded letter
   }
}
