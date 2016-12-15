#include <stdio.h>
main()
{
int pid;
printf("I'm the original process with PID %d and PPID\
 %d\n",getpid(),getppid());
pid=fork();
if(pid!=0)
{
printf("I'm the parent process with PID %d and PPID\
 %d\n",getpid(),getppid());
printf("My child PID is %d\n",pid);
printf("fork() in the parent process return %d\n",pid);
}
else{
 printf("I'm the child process with PID %d and PPID\
 %d\n",getpid(),getppid());
 printf("fork() in the child process return %d\n",pid);	
}
printf("PID %d terminates\n",getpid());

}
/*Output:
I'm the original process with PID 15196 and PPID 15014
I'm the child process with PID 15197 and PPID 15196
fork() in the child process return 0
PID 15197 terminates
I'm the parent process with PID 15196 and PPID 15014
My child PID is 15197
fork() in the parent process return 15197
PID 15196 terminates*/
