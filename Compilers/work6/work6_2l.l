%%
[^ \t\n]+	{strcpy(yylval.str,yytext);return STRING;}
[ \t\n]+	return ((int)' ');
.|\n	;
%%
