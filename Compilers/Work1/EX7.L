%%
[0-9]+ printf("NUMBER");
[a-zA-Z]+ printf("WORD");
[a-zA-Z0-9]+ printf("STRING");
"*" {printf("END");exit(0);}
%%
