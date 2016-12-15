#include <iostream.h>
#include <string.h>
#include <stdlib.h>

const char alphabet[36]={'A','B','C','D','E','F',
						 'G','H','I','J','K','L',
						 'M','N','O','P','Q','R',
						 'S','T','U','V','W','X',
						 'Y','Z','1','2','3','4',
						 '5','6','7','8','9','0'};

const char *morse[36]={".-","-...","-.-.","-..",".","..-.",
					   "--.","....","..",".---","-.-",".-..",
					   "--","-.","---",".--.","--.-",".-.",
					   "...","-","..-","...-",".--","-..-",
					   "-.--","--..",".----","..---","...--","....-",
					   ".....","-....","--...","---..","----.","-----"};

void from_morse()
{
	char st[256];
	char letter[6];
	char ch=0;
	int index=0;
	int blank=0;
	int i=0;
	cout <<"Enter the Morse code : "<<endl;
	cin.getline(st,256);
	while (i<strlen(st))
	{
		ch=0;
		index=0;
		blank=0;
		while (st[i]==' '&&i<strlen(st))
		{
			i++;
			blank++;
		}
		while (i<strlen(st)&&st[i]!=' ')
		{
			letter[index]=st[i];
			index++;
			i++;
		}
		letter[index]='\x0';
		for (int j=0 ;j<36; j++)
			if (!strcmp(letter,morse[j]))
				ch=alphabet[j];
		if (ch==0)
		{
			cout <<endl<< "Invalid code"<<endl;
			exit(1);
		}
		if (blank==3)
			cout <<" "<<ch<<flush;
		else cout <<ch<<flush;
	}
	cout <<endl;
}

void to_morse()
{
	char st[256];
	int i=0;
	bool flag=false;
	cout <<"Enter an English-language phrase : "<<endl;
	cin.getline(st,256);
	while (i<strlen(st))
	{
		flag=false;
		if (st[i]!=' ')
		{
			for (int j=0; j<36; j++)
				if (alphabet[j]==st[i])
				{
					flag=true;
					cout <<morse[j]<<" "<<flush;
				}
			if (!flag)
			{
				cout <<endl<<"Invalid symbol"<<endl;
				exit(1);
			}
		}
		else
			cout <<"  "<<flush;
		i++;
	}
	cout <<endl;
}

void main()
{
	from_morse();
	to_morse();
}