/*
A process may replace its current code, data, stack with those of another
executable by using one exec(). When a process executes an "exec()" system
call, its PID and PPID numbers stay the same, only the code  that the
process is executing changes.
*/

#include <stdio.h>
main()
{
int r_pid;
r_pid=fork();
if(r_pid<0)
{
printf("No child process created\n");
exit(1);
}
if(r_pid>0){
printf("I'm the parent process %d and I'm about to exec and ls\
-l\n",getpid());
execl("/bin/ls","-l",NULL);
printf("This line should never be executed\n");
}
if(r_pid==0){
printf("I'm the child process %d and I'm about to execute \
\"echo\"\n",getpid());
execl("/bin/echo","echo","Hello, how are you?",NULL);
printf("This line should never be executed\n");
}
}
/*
Output:

I'm the child process 10933 and I'm about to execute "echo"
Hello, how are you?
I'm the parent process 10932 and I'm about to exec and ls-l
a.out     execl1.c  f2        f5        fork3.c   n
e1        f         f3        fork1.c   fork4.c   n1
exec1.c   f1        f4        fork2.c   fork5.c   nice1.c
*/
