/*Two types of operations can be carried on a semaphore: wait and signal.
 A set operation first checks if the semaphore's value equals some number. 
 If it does, it decreases its value and returns. If it does not,
 the operation blocks the calling process until the semaphore's value reaches
 the desired value.
 A signal operation increments the value of the semaphore, possibly awakening
 one or more processes that are waiting on the semaphore. 
 How this mechanism can be put to practical use will be explained soon. 
 A semaphore set is a structure that stores a group of semaphores
 together, and
 possibly allows
 the process to commit a transaction on part or all of the semaphores in the
 set together. 



        struct semid_ds {
                struct ipc_perm sem_perm;      permissions .. see ipc.h 
                time_t          sem_otime;       last semop time 
                time_t          sem_ctime;       last change time 
                struct sem      *sem_base;       ptr to first semaphore in array 
                struct wait_queue *eventn;
                struct wait_queue *eventz;
                struct sem_undo  *undo;          undo requests on this array 
                ushort          sem_nsems;       no. of semaphores in array 
        };
         

	One semaphore structure for each semaphore in the system. 

        struct sem {
                short   sempid;          pid of last operation 
                ushort  semval;          current value 
                ushort  semncnt;         num procs awaiting increase in semval 
                ushort  semzcnt;         num procs awaiting semval = 0

        };
	union semun{
		int val;
		struct semid_ds *buff;
		unsigned short *array;
	};
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_RESOURCE_MAX        1       /* Initial value of all semaphores
*/

void opensem(int *sid, key_t key);
void createsem(int *sid, key_t key, int members);
void locksem(int sid, int member);
void unlocksem(int sid, int member);
void removesem(int sid);
unsigned short get_member_count(int sid);
int getval(int sid, int member);
void dispval(int sid, int member);
void changemode(int sid, char *mode);
void usage(void);

int main(int argc, char *argv[])
{
        key_t key;
        int   semset_id;

        if(argc == 1)
                usage();

        /* Create unique key via call to ftok() */
        key = ftok(".", 's');

        switch(tolower(argv[1][0]))
        {
                case 'c': if(argc != 3)
                                usage();
                          createsem(&semset_id, key,  atoi(argv[2]));
                          break;
                case 'l': if(argc != 3)
                                usage();
                          opensem(&semset_id, key);
                          locksem(semset_id, atoi(argv[2]));
                          break;
                case 'u': if(argc != 3)
                                usage();
                          opensem(&semset_id, key);
                          unlocksem(semset_id, atoi(argv[2]));
                          break;
                case 'd': opensem(&semset_id, key);
                          removesem(semset_id);
                          break;        
                case 'm': opensem(&semset_id, key);
                          changemode(semset_id, argv[2]);
                          break;        
                 default: usage();

        }
        
        return(0);
}

void opensem(int *sid, key_t key)
{
        /*In order to create a new semaphore set, or access an existing
	set, the semget() system call is used
 	Open the semaphore set - do not create!
	middle  argument of semget(): no. of semaphores in array  */

        if((*sid = semget(key, 0, 0666)) == -1) 
        {
                printf("Semaphore set does not exist!\n");
                exit(1);
        }

}

void createsem(int *sid, key_t key, int members)
{
        int cntr;
        union semun semopts;

        if(members > 32) {
                printf("Sorry, max number of semaphores in a set is 32\n");
                exit(1);
        }

        printf("Attempting to create new semaphore set with %d members\n",
                                members);

        if((*sid = semget(key, members, IPC_CREAT|IPC_EXCL|0666))
                        == -1) 
        {
                fprintf(stderr, "Semaphore set already exists!\n");
                exit(1);
        }

        semopts.val = SEM_RESOURCE_MAX;
        
       /* Initialize all members (could be done with SETALL)

int semctl ( int semid, int semnum, int cmd, union semun arg );
*/
/*The first argument to semctl() is the key value (in our case returned
by a call to semget). The second argument (semun) is the semaphore number
that an operation is targeted towards. In essence, this can be thought of
as an index into the semaphore set, with the first semaphore (or only one)
in the set being represented by a value of zero (0).
The cmd argument represents the command to be performed against the set.
As you can see, the familiar IPC_STAT/IPC_SET commands are present, along
with a wealth of additional commands specific to semaphore sets:
*/        

		for(cntr=0; cntr<members; cntr++)
                semctl(*sid, cntr, SETVAL, semopts);
}

void locksem(int sid, int member)
{
    /*int semop ( int semid, struct sembuf *sops, unsigned nsops);
    
        struct sembuf {
                ushort  sem_num;         The number of the semaphore you wish to deal with 
                short   sem_op;         The operation to perform (positive, negative, or zero)  
                short   sem_flg;       operation flags 
        };
*/    
	struct sembuf sem_lock={ 0, -1, IPC_NOWAIT};

		/*IPC_NOWAIT is specified, so the call will either go through immediately, 
or fail if another print job is currently printing.*/
		
        if( member<0 || member>(get_member_count(sid)-1))
        {
                fprintf(stderr, "semaphore member %d out of range\n",member);
                return;
        }

        /* Attempt to lock the semaphore set */
        if(!getval(sid, member))
        {
                fprintf(stderr, "Semaphore resources exhausted (no lock)!\n");
                exit(1);
        }
        
        sem_lock.sem_num = member;
        
        if((semop(sid, &sem_lock, 1)) == -1)
        {
                fprintf(stderr, "Lock failed\n");
                exit(1);
        }
        else
                printf("Semaphore resources decremented by one (locked)\n");

        dispval(sid, member);
}

void unlocksem(int sid,int member)
{
int semval; 
       struct sembuf sem_unlock;
 sem_unlock.sem_num=member,
sem_unlock.sem_op= 1;
sem_unlock.sem_flg=IPC_NOWAIT;

        if( member<0 || member>(get_member_count(sid)-1))
        {
                fprintf(stderr, "semaphore member %d out of range\n",member);
                return;
        }

        /* Is the semaphore set locked? */
        semval = getval(sid, member);
        if(semval == SEM_RESOURCE_MAX) {
                fprintf(stderr, "Semaphore not locked!\n");
                exit(1);
        }

        sem_unlock.sem_num = member;

        /* Attempt to lock the semaphore set */
        if((semop(sid, &sem_unlock, 1)) == -1)
        {
                fprintf(stderr, "Unlock failed\n");
                exit(1);
        }
        else
                printf("Semaphore resources incremented by one (unlocked)\n");

        dispval(sid, member);
}

void removesem(int sid)
{
/* 
IPC_RMID: Removes the set from the kernel. 

*/
	semctl(sid, 0, IPC_RMID, 0);
        printf("Semaphore removed\n");
}

unsigned short get_member_count(int sid)
{
        union semun semopts;
        struct semid_ds mysemds;

        semopts.buf = &mysemds;

        /* Return number of members in the semaphore set */
        return(semopts.buf->sem_nsems);
}

int getval(int sid, int member)
{
        int semval;
/*GETVAL: 
Returns the value of a single semaphore within the set. 
*/
        semval = semctl(sid, member, GETVAL, 0);
        return(semval);
}

void changemode(int sid, char *mode)
{
        int rc;
        union semun semopts;
        struct semid_ds mysemds;

        /* Get current values for internal data structure */
        semopts.buf = &mysemds;
/*IPC_STAT: 
Retrieves the semid_ds structure for a set, and stores it in the address of the buf argument in the semun union. 
*/
        rc = semctl(sid, 0, IPC_STAT, semopts);

        if (rc == -1) {
                perror("semctl");
                exit(1);
        }
                
        printf("Old permissions were %o\n", semopts.buf->sem_perm.mode);
                
        /* Change the permissions on the semaphore */
        sscanf(mode, "%ho", &semopts.buf->sem_perm.mode);

        /* Update the internal data structure */
 /*IPC_SET: 
Sets the value of the ipc_perm member of the semid_ds structure for a set. Takes the values from the buf argument of the semun union. 
*/


		semctl(sid, 0, IPC_SET, semopts);

        printf("Updated...\n");

}

void dispval(int sid, int member)
{
        int semval;
/*
GETVAL :
Returns the value of a single semaphore within the set. 
*/

        semval = semctl(sid, member, GETVAL, 0);
        printf("semval for member %d is %d\n", member, semval);
}

void usage(void)
{
        fprintf(stderr, "semtool - A utility for tinkering with semaphores\n");
        fprintf(stderr, "\nUSAGE:  semtool4 (c)reate <semcount>\n");
        fprintf(stderr, "                 (l)ock <sem #>\n");
        fprintf(stderr, "                 (u)nlock <sem #>\n");
        fprintf(stderr, "                 (d)elete\n");
        fprintf(stderr, "                 (m)ode <mode>\n");
        exit(1);
}
