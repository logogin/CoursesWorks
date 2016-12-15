DIGIT	[0-9]
WORD	[^ \t\n]
    int i;
    int flag=0;
    int sum_min=0;
    int sum_max=0;
    int num1=0;
    int num2=0;
    char min[80];
    char max[80];
%%
{DIGIT}+"."{DIGIT}+	{i=0;
			num1=0;
			num2=0;
			while(yytext[i]!='.')
			    num1+=yytext[i++]-0x30;
			i=1;
			while(yytext[yyleng-i]!='.')
			    num2+=yytext[yyleng-i++]-0x30;
			if (!flag)
			{
			    flag=1;
			    sum_max=num1;
			    sum_min=num2;
			    strcpy(max,yytext);
			    strcpy(min,yytext);
			}
			else
			{
			    if (num1>sum_max)
			    {
				    sum_max=num1;
				    strcpy(max,yytext);
			    }
			    if (num2<sum_min)
			    {
				sum_min=num2;
				strcpy(min,yytext);
			    }
			}
			}
{WORD}+{DIGIT}+"."{DIGIT}+{WORD}*	|
{WORD}*{DIGIT}+"."{DIGIT}+{WORD}+	|
.|\n	;
%%
main()
{
    yylex();
    printf("Maximum %s\nMinimun %s\n",max,min);
}