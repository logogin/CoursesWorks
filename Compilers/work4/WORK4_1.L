	char digits[80];
	char letters[80];
	int d_size=0;
	int l_size=0;
	int i;
%%
[0-9]		{digits[d_size]=yytext[0];
			d_size++;}
[A-Za-z]	{letters[l_size]=yytext[0];
			l_size++;}
.|\n	;
%%
main()
{
	yylex();
	for(i=0; i<d_size; i++)
		printf("%c",digits[i]);
	puts("");
	for(i=0; i<l_size; i++)
		printf("%c",letters[i]);
	puts("");
}
