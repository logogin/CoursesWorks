/*
Every process has a priority between -20 and +19
that effects the amount of CPU time that its allocated. The smaller the
priority value, the faster the process will run. Only superuser can have
negative priority value and login shells start with priority value of
zero.
*/

#include <stdio.h>
main(){
printf("Original priority\n");
system("ps");
nice(0);
printf("Running at priority 0\n");
system("ps");
nice(10);
printf("Running at priority 10\n");
system("ps");}
