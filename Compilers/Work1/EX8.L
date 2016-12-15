%%
 int num=0,word=0,str=0;
[0-9]+ num++;
[a-zA-Z]+ word++;
[a-zA-Z0-9]+ str++;
"*" {printf("Num=%d,Word=%d,Str=%d",num,word,str);exit(0);}
%%
