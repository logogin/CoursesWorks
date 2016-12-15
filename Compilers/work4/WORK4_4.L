	char word[80];
	char temp[80];
	char letter;
	int flag=0;
	int flag1;
	int word_len;
	int i;
	int j;
%%
[^ \t\n]+	{if (!flag)
		{
		    flag=1;
		    strcpy(word,yytext);
		    word_len=strlen(word);
		    puts(word);
		}
		else
		{
		    flag1=1;
		    strcpy(temp,yytext);
		    if (word_len<=strlen(temp))
		    for (i=0; i<=strlen(temp)-word_len; i++)
		    {
			letter=temp[word_len+i];
			temp[word_len+i]='\x0';
			if (!strcmp(temp+i,word))
				flag1=0;
			temp[word_len+i]=letter;
		    }
		    if (flag1)
		    	ECHO;
		}
		}
.|\n	ECHO;
%%
