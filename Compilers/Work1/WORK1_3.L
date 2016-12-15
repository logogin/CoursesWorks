%%
-?[0-9]+[ \t\n]+			printf("int%c",yytext[yyleng-1]);
-?[0-9]+"."[0-9]+[ \t\n]+		printf("float%c",yytext[yyleng-1]);
-?[0-9]+"."[0-9]+[eE][-+][0-9]+[ \t\n]+	printf("exp%c",yytext[yyleng-1]);
%%
