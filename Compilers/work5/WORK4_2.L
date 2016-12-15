	char word[80];
	int count[80]={0};
	int flag=0;
	int i=0;
	int j=0;
%%
[^ \t\n]+	{if (!flag)
			{
				strcpy(word,yytext);
				flag=1;
			}
			else
				for (i=0; i<strlen(word); i++)
					for (j=0; j<strlen(yytext); j++)
						if (word[i]==yytext[j])
							count[i]++;
			}
.|\n	;
%%
main()
{
    yylex();
    for (i=0; i<strlen(word); i++)
		printf("%c=%d ",word[i],count[i]);
	puts("");
}