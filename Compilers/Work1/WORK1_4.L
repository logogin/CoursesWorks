%%
[ \t\n]+	printf("%c",yytext[yyleng-1]);
[^A-Za-z]	;
%%
