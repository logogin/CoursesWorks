/*
A parent process may wait for one of its children to terminate and then
accept its child's termination code by executing "wait()"
A successfull call to "wait()" return PID of the child that terminated and
places a status code into "status" 
*/
 #include <stdio.h>
main(){
int pid,status,childPid;
printf("I'm the parent process and my PID is %d\n",getpid());
printf("I'm the parent process with PID %d and PPID\
 %d\n",getpid(),getppid());
childPid=wait(&status);
printf("A child with PID %d terminated with exit code %d\n",childPid,
       status>>8);
pid=fork();
if(pid!=0)
{
printf("I'm the parent process with PID %d and PPID\
 %d\n",getpid(),getppid());
childPid=wait(&status);
printf("A child with PID %d terminated with exit code %d\n",childPid,
       status>>8);
}
else {
 printf("I'm the child process with PID %d and PPID\
 %d\n",getpid(),getppid());
exit(42);}
printf("PID %d terminates\n",getpid());
}
/*Output:
I'm the parent process and my PID is 15582
I'm the parent process with PID 15582 and PPID 15014
A child with PID -1 terminated with exit code 0
I'm the child process with PID 15583 and PPID 15582
I'm the parent process with PID 15582 and PPID 15014
A child with PID 15583 terminated with exit code 42
PID 15582 terminates
*/
