DIGIT	[0-9]
    int sum1=0;
    int sum2=0;
    int num;
%%
{DIGIT}+	{num=atoi(yytext);if (num%2) sum2+=num; else sum1+=num;}
[^ \t\n]+{DIGIT}+[^ \t\n]*	|
[^ \t\n]*{DIGIT}+[^ \t\n]+	;
%%
main()
{
    yylex();
    printf("Sum of odd numbers %d\nSum of even numbers %d\n",sum1,sum2);
}
