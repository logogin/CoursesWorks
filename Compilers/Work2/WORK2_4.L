%%
^(for)[^ \t\n]*		{ECHO;printf(" ");}
[ \t]+(for)[^ \t\n]*	{ECHO;printf(" ");}
\n			ECHO;
.			;
%%