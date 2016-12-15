	int sum=0;
%%
[0-9]	{sum+=yytext[0]-0x30;
		if (sum<65)
		    sum*=10;
		else
		{
		    sum-=0x20;
		    printf("%d",sum);
		    sum=0;
		}
		}
%%
