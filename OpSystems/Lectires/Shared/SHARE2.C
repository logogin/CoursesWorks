#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SEGSIZE 100

main()
{
        key_t key;
        int   shmid;
        char  *segptr;
		int r_pid;

         key = ftok(".", 'S');

        if((shmid = shmget(key, SEGSIZE, IPC_CREAT|IPC_EXCL|0666)) == -1) 
 
       {
                printf("Shared memory segment exists - opening as client\n");

                if((shmid = shmget(key, SEGSIZE, 0)) == -1) 
                {
                        perror("shmget");
                        exit(1);
                }
        }
        else
        {
                printf("Creating new shared memory segment\n");
        }


        if((segptr = shmat(shmid, 0, 0)) == NULL)
        {
                perror("shmat");
                exit(1);
        }
		
		r_pid=fork();
		
		if(r_pid<0)
		{
			printf("No child created");
			exit(1);
		}
		else if(r_pid==0)
		{
	       printf("The child process with PID number : %d"
               " (his parent PID is %d) writes a text to the shared"
               " memory\n",getpid(),getppid());
		strcpy(segptr,"This text is written by the child process"); 
		}
		else
		{
	         printf(" The following text is received by the "
	                "parent process with PID number %d: %s\n",
                 getpid(),segptr);
		}
		shmctl(shmid, IPC_RMID, 0);
}

/*
Output:

Creating new shared memory segment
The child process with PID number : 16715 (his parent PID is 16714) writes
a text to the shared memory
 The following text is received by the parent process with PID number
16714: This text is written by the child process

*/
