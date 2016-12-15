%{
int flag=0;
%}
%%
[^, \t\n]	{yylval=yytext[0];
		return LETTER;
		}
","	return yytext[0];
[ \t\n]+	;
%%
