//#include "pv.h"
#include <semaphore.h>

/* initsem -- semaphore initialization */

void initsem(sem_t *semptr,const unsigned int value)
{
   if (sem_init(semptr,0,value)<0)
   {
	   perror("'sem_init' filead!!!\n");
	   exit(1);
   }
}
    
/* p -- semaphore p operation */
/* We use 'p' here, rather than more understandable 'wait', since the latter */
/* can be confused with the Unix 'wait'. */

void p(sem_t *semptr)
{
	sem_wait(semptr);
}
   

/* v -- semaphore v operation */

void v(sem_t *semptr)
{
	if (sem_post(semptr)<0)
	{
		perror("'sem_post' filed!!!\n");
		exit(1);
	}
}

int getsemvalue(sem_t *semptr)
{
	int value;
	sem_getvalue(semptr,&value);
	return value;
}

void destroysem(sem_t *semptr)
{
	if (sem_destroy(semptr)<0)
	{
		perror("'sem_destroy' filed!!!\n");
		exit(1);
	}
}

/*int main()
{
	return 0;
}*/
