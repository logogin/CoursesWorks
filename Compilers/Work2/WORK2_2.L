			int lines=0;
			int words=0;
%%
"\n"		lines++;
[^ \n\t]+	words++;
<<EOF>>		{lines++;yyterminate();}
.		;
%%
main()
{
  yylex();
  printf("Number of words %d\nNumber of lines %d\n",words,lines);
    
}
