DIGIT	[0-9]
WORD	[^ \t\n]
    int i;
    char num1[80];
    char num2[80];
%%
{DIGIT}+"."{DIGIT}+	{i=0;
			while(yytext[i]!='.') 
			{
			    num1[i]=yytext[i];
			    i++;    
			}
			num1[i]='\x0';
			i++;
			while(i!=yyleng)
			{
			    num2[i-strlen(num1)-1]=yytext[i];
			    i++;
			}
			num2[i]='\x0';
			printf("%s.%s",num2,num1);
			}
{WORD}+{DIGIT}+"."{DIGIT}+{WORD}*	|
{WORD}*{DIGIT}+"."{DIGIT}+{WORD}+	|
.|\n	ECHO;
%%
