	char word[80];
	int len;
	int flag=0;
	int i=0;
%%
[^ \t\n]+	{if (!flag)
		{
		    strcpy(word,yytext);
		    len=strlen(word);
		    flag=1;
		}
		else
		    for (i=0; i<len; i++)
		        if (word[i]!=yytext[i])
				word[i]=0;
		}
.|\n	;
%%
main()
{
    yylex();
	for (i=0; i<len; i++)
	    if (word[i])
		printf("%c ",word[i]);
	puts("");
}