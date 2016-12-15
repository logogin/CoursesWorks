// 22.11.2000 Dmitry Zavyalov (c)
//
// 5.47  Morse Code ...

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void encode (char *, char **);
main()  {
//                   0         1         2         3         4
char *morse[36]={ "_____",  ".____",  "..___",  "...__",  "...._",
//                   5         6         7         8         9
		  ".....",  "_....",  "__...",  "___..",  "____.",
//                  a       b        c      d      e        f       g
		  "._",   "_...", "_._.", "_..",  ".",    ".._.", "__.",
//                  h       i        j      k      l        m       n
		  "....", "..",   ".___", "_._",  "._..", "__",   "_.",
//                  o       p        q      r       s      t        u
		  "___",  ".__.", "__._", "._.",  "...",  "_",    ".._",
//                  v       w       x       y       z
		  "..._", ".__",  "_.._", "_.__", "__.."  };
char English_Text[255];
   clrscr();
   gets(English_Text);
   encode(English_Text, morse);

   cout<<endl
	   <<endl;
   cout<<"Press any key to continue...";
   getch();
   return (0);

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