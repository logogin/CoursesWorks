%s FLAG
%%
"for ()"			{BEGIN FLAG;return FOR;}
"while ()"			{BEGIN FLAG;return WHILE;}
"do"				{BEGIN FLAG;return DO;}
<FLAG>";"			return yytext[0];
<FLAG>"{"			return yytext[0];
<FLAG>"}"			return yytext[0];
<FLAG>[A-Za-z0-9]+	return SENTENCE;
.|\n	;
%%
