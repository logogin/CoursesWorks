#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SEGSIZE 100

main(int argc, char *argv[])
{
        key_t key;
        int   shmid, cntr;
        char  *segptr;

        if(argc == 1)
                usage();

        /* Create unique key via call to ftok() 
One of the problems with SysV IPC methods is the need to choose a unique
identifier for our processes. How can we make sure that the identifier of
a shared memory in our project won't collide with the identifier of a
shared memory in some other program installed on the system? 

To help with that, the ftok() system call was introduced. This system call
accepts two parameters, a path to a file and a character, and generates a
more-or-less unique identifier. It does that by finding the "i-node"
number of the file (more or less the number of the disk sector containing
this file's information), combines it with the second parameter, and thus
generates an identifier, that can be later fed to semget, shmget() or
msgget(). Here is how to use ftok(): 


*/
        key = ftok(".", 'S');

        /* Open the shared memory segment - create if necessary 
If several processes try to allocate a segment using the same ID, they
will all get an identifier for the same page, unless they defined IPC_EXCL
in the flags to shmget(). In that case, the call will succeed only if the
page did not exist before.The queue created belongs to the user whose
process created the queue.Thus, since the permission bits are '0600',
only processes run on behalf of this user will have access to the queue 
*/


        if((shmid = shmget(key, SEGSIZE, IPC_CREAT|IPC_EXCL|0666)) == -1) 
 
       {
                printf("Shared memory segment exists - opening as client\n");

                /* Segment probably already exists - try as a client */

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

/* Attach (map) the shared memory segment into the current process
*/
        if((segptr = shmat(shmid, 0, 0)) == NULL)
        {
                perror("shmat");
                exit(1);
        }
        
        switch(tolower(argv[1][0]))
        {
                case 'w': writeshm(shmid, segptr, argv[2]);
                          break;
                case 'r': readshm(shmid, segptr);
                          break;
                case 'd': removeshm(shmid);
                          break;
                case 'm': changemode(shmid, argv[2]);
                          break;
                 default: usage();

        }
}

writeshm(int shmid, char *segptr, char *text)
{
        strcpy(segptr, text);
        printf("Done...\n");
}

readshm(int shmid, char *segptr)
{
        printf("segptr: %s\n", segptr);
}

removeshm(int shmid)
{

 /*IPC_RMID: Markes a segment for removal.
*/

	shmctl(shmid, IPC_RMID, 0);
        printf("Shared memory segment marked for deletion\n");
}

changemode(int shmid, char *mode) 
{
        struct shmid_ds myshmds;

/* Get current values for internal data structure 
IPC_STAT: Retrieves the shmid for a segment and stores it in the
address of the myshmds argument */

        shmctl(shmid, IPC_STAT, &myshmds);

 /* Display old permissions */
        
	printf("Old permissions were: %o\n", myshmds.shm_perm.mode);

/* Convert and load the mode */
	
        sscanf(mode, "%o", &myshmds.shm_perm.mode);

/* Update the mode
IPC_SET: Sets the value of the shmid for a segment.Takes the value
from the myshmd argument */
        
        shmctl(shmid, IPC_SET, &myshmds);

        printf("New permissions are : %o\n", myshmds.shm_perm.mode);
}

usage()
{
        fprintf(stderr, "shmtool - A utility for tinkering with shared memory\n");
        fprintf(stderr, "\nUSAGE:  shmtool (w)rite <text>\n");
        fprintf(stderr, "                (r)ead\n");
        fprintf(stderr, "                (d)elete\n");
        fprintf(stderr, "                (m)ode change <octal mode>\n");
        exit(1);
}

/*
Output:

/users/popeye/segel/gidig/OS-33->!cc
cc -o mes1 mes1.c
/users/popeye/segel/gidig/OS-34->mes1 w hello
Shared memory segment exists - opening as client
Done...
/users/popeye/segel/gidig/OS-35->mes1 d
Shared memory segment exists - opening as client
Shared memory segment marked for deletion
/users/popeye/segel/gidig/OS-36->mes1 w hello
Creating new shared memory segment
Done...

*/
