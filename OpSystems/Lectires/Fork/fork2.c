/*If the parent dies before its child terminates, the child is
automatically adopted by the original "init" process, PID 1.*/
#include <stdio.h>
main()
{
int pid;
printf("I'm the original process with process with PID %d and PPID %d\n",
getpid(),getppid());
pid=fork();
if(pid!=0){
 printf("I'm the parent process with PID %d and PPID %d\n",
    getpid(),getppid());
 printf("My child's PID is %d\n",pid);
}
else{
 sleep(5);
 printf("I'm the child process with PID %d and PPID %d\n",
    getpid(),getppid());
}
printf("PID %d terminates\n",getpid());
}
 /*
Output:
I'm the original process with process with PID 15280 and PPID 15014
I'm the parent process with PID 15280 and PPID 15014
My child's PID is 15281
PID 15280 terminates
/users/popeye/segel/gidig/OS-51->I'm the child process with PID 15281 and
PPID 1
PID 15281 terminates*/
