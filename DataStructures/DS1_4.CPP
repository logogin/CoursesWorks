#include <iostream.h>
#include <string.h>

void permutation (char *str,int letter, int size)
{
	char ch;
	if (letter==size)
		cout <<str<<"   ";
	else
	{   
		for (int i=letter; i<size; i++)
		{
			ch=str[letter];
			str[letter]=str[i];
			str[i]=ch;
			permutation(str,letter+1,size);
			ch=str[letter];
			str[letter]=str[i];
			str[i]=ch;
		}
	}
}

void main()
{
	char str[255];
	cout << "Enter the string : "<<endl;
	cin >> str;
	cout << endl;
	permutation(str,0,strlen(str));
}