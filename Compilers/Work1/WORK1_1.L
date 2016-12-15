%%
[ \t]+	printf(" ");
[a-z]	putchar(yytext[0]-(int)('a'-'A'));
[A-Z]	putchar(yytext[0]+(int)('a'-'A'));
%%