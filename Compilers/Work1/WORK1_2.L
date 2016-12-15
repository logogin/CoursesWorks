%%
[A-Za-z][ \t\n]+		printf("char%c",yytext[yyleng-1]);
[0-9]+[ \t\n]+			printf("number%c",yytext[yyleng-1]);
[A-Za-z]+[ \t\n]+		printf("word%c",yytext[yyleng-1]);
[0-9A-Za-z]+[ \t\n]+		printf("string%c",yytext[yyleng-1]);
%%
