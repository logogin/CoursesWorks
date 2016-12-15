/*
This example takes the arguments from the prompt as the input 
*/

#include <stdio.h>
main(argc,argv)
int argc;
char * argv[];
{
 if(fork()==0){
printf("The child process compiles a C source file named %s\n",argv[4]);
printf("The parent process is about to execute the compiled %s \
file\nThe Output of this file is:\n",argv[4]);
execvp(argv[1],&argv[1]);
fprintf(stderr,"Could not execute %s\n",argv[1]);}
if(fork()>0)
 {
sleep(5);
/*printf("The parent process is about to execute the compiled %s \
file\nThe Output of this file is:\n",argv[4]);*/
execl("./n1","n1");
} 

}
/*
Output:

e2 cc -o n1 nice1.c
The child process compiles a C source file named nice1.c
The parent process is about to execute the compiled nice1.c file
The Output of this file is:
Original priority
   PID TTY      TIME COMD
 11074 ttyq5    0:04 tcsh
 11860 ttyq5    0:00 ps
 11852 ttyq5    0:00 n1
 11859 ttyq5    0:00 sh
Running at priority 0
   PID TTY      TIME COMD
 11074 ttyq5    0:04 tcsh
 11862 ttyq5    0:00 ps
 11852 ttyq5    0:00 n1
 11861 ttyq5    0:00 sh
Running at priority 10
   PID TTY      TIME COMD
 11074 ttyq5    0:04 tcsh
 11864 ttyq5    0:00 ps
 11852 ttyq5    0:00 n1
 11863 ttyq5    0:00 sh
*/
