DIGIT	[0-9]
    int *array;
    int size=0;
    int sum;
    int i;
%%
{DIGIT}+	{if ((yyleng>1)&&!((yytext[yyleng-1]-0x30)%2))
		    {
			sum=0;
			size++;
			for (i=1; i<yyleng; i+=2)
			    sum+=yytext[i]-0x30;
			array=(int *)realloc(array,size);
			array[size-1]=sum;
		    }
		}
[^ \t\n]+{DIGIT}+[^ \t\n]*	|
[^ \t\n]*{DIGIT}+[^ \t\n]+	;
%%
main()
{
    yylex();
    for (i=0; i<size; i++)
	printf("%d ",array[i]);
    free(array);
    printf("\n");
}
