%%
[0-9]	{yylval=yytext[0]-0x30;return DIGIT;}
[ ]+	return yytext[0];
"."		return yytext[0];
%%

