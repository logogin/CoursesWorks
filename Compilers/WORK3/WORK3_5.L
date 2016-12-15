DIGIT	[0-9]
WORD	[^ \t\n]
    int i;
    int j=0;
    int pos;
    char st1[80];
    char st2[80];
%%
-?{DIGIT}+"."{DIGIT}+(E|e)(-?){DIGIT}+	|
-?{DIGIT}+(E|e)(-?){DIGIT}+	{i=0;
				j=0;
				pos=0;
				while(yytext[i]!='E'&&yytext[i]!='e')
				{
				    if (yytext[i]!='.')
				    {
					st1[j]=yytext[i];
					j++;
				    }
				    else
					pos=i;
				    i++;
				}
				st1[j]='\x0';
				i++;
				j=0;
				for (;i<=yyleng;i++,j++)
				    st2[j]=yytext[i];
				if (pos==0)
				    pos=strlen(st1);
				pos+=atoi(st2);
				if (pos<0)
				{
				    printf("0.");
				    for (i=0; i<abs(pos); i++)
					printf("0");
				    printf("%s",st1);
				}
				if (pos>0)
				{
				    for (i=0; i<pos; i++)
				    	if (i<strlen(st1))
					    printf("%c",st1[i]);
					else
					    printf("0");
				    
				    if (i<strlen(st1)-1)
				    {
					printf(".");
					for(;i<strlen(st1); i++)
					    printf("%c",st1[i]);
				    }
				    else
					printf(".0");
				}
				if (pos==0)
				    printf("0.%s",st1);
				}
{WORD}*-?{DIGIT}+"."{DIGIT}+(E|e)(-?){DIGIT}+{WORD}+	|
{WORD}+-?{DIGIT}+"."{DIGIT}+(E|e)(-?){DIGIT}+{WORD}*	|
{WORD}*-?{DIGIT}+(E|e)(-?){DIGIT}+{WORD}+	|
{WORD}+-?{DIGIT}+(E|e)(-?){DIGIT}+{WORD}*	|
.|\n	ECHO;
%%
