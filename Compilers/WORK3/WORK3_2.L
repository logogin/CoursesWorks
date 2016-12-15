    char array[3][80];
    char temp[80];
    int i=0;
%%
[A-Za-z]+	strcpy(array[i++],yytext);
%%
main()
{
    yylex();
    if (strcmp(array[0],array[1])>0)
    {
	strcpy(temp,array[0]);
	strcpy(array[0],array[1]);
	strcpy(array[1],temp);
    }
    if (strcmp(array[0],array[2])>0)
    {
	strcpy(temp,array[0]);
	strcpy(array[0],array[2]);
	strcpy(array[2],temp);
    }
    if (strcmp(array[1],array[2])>0)
    {
	strcpy(temp,array[1]);
	strcpy(array[1],array[2]);
	strcpy(array[2],temp);
    }
    for (i=0; i<3; i++)
	printf("%s ",array[i]);
    printf("\n");
}
