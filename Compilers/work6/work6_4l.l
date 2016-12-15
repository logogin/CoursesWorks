%%
[a-zA-Z]	{yylval.intval=yytext[0];return LETTER;}
[0-9]		{yylval.intval=yytext[0];return DIGIT;}
"!="		{yylval.intval=0;return OPERATOR;}
"=="		{yylval.intval=1;return OPERATOR;}
"if"		return IF;
"="			return yytext[0];
"("			return yytext[0];
")"			return yytext[0];
[ \t\n]+	return ((int)' ');
.|\n		ECHO;
%%

