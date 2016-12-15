/*ZOMBIE PROCESS
A process that terminates cannot leave the system until its parents
accepts its return code. If the parent is already dead, it will already
been adopted by the "init" process, which always accept its children's
return code. However, if a process parent is alive, but the parent never
executes a "wait()" system call, the process will remain a zombie*/

#include <stdio.h>
main(){
int pid;
pid=fork();
if(pid!=0)
{
 while(1) 
 sleep(1000);
 }
 else 
  exit(42);
 } 
 
