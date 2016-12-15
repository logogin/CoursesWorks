#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include    <sys/types.h>
#include    <sys/ipc.h>
#include    <sys/sem.h>
#include    <errno.h>
#define SEMKEY 123456L      /* key value for semget() */
#define PERMS  0666
#define MAXBUFF 1000

static struct sembuf    op_lock[2]={
    0 , 0, 0,        /*wait for sem#0 to become 0*/
    0 , 1, 0        /*increment sem#0 to 1 */
};

static struct sembuf op_unlock[1]={
    0, -1 , IPC_NOWAIT  /*decrement sem0 by 1 */
};

int semid = -1;      /* semaphore id */

void my_lock(){
    if (semid < 0) {
        if( (semid = semget(SEMKEY, 1, IPC_CREAT | PERMS)) < 0)
            perror("semget error");
	 }
    if (semop(semid, &op_lock[0],2)<0)
        perror("semop lock error");
}

void my_unlock(){
    if(semop(semid, &op_unlock[0], 1) < 0)
        perror("semop unlock error");
}

int main  (int argc, char *argv[])
{
    char buffer[MAX_CANON];
    char *c;
    int i;
    int n;
    pid_t childpid;

    if ( (argc != 2) || ((n = atoi(argv[1])) <= 0) ) {
       fprintf (stderr, "Usage: %s number_of_processes\n", argv[0]);
       exit(1);
    }

    for (i = 1; i < n;  ++i)
       if (childpid = fork())
          break;
				my_lock();
    sprintf(buffer,
       "i:%d  process ID:%ld  parent ID:%ld  child ID:%ld\n",
       i, (long)getpid(), (long)getppid(), (long)childpid);

    c = buffer;
       /*****************start of critical section ********************/
    while (*c != '\0') {
sleep(2);       
fputc(*c, stderr);
       c++;
    }
    fputc('\n', stderr);
       /*******************end of critical section ********************/

	 my_unlock();
return 0;
}
