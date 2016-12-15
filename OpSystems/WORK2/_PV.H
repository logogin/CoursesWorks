/* semaphore example header file */

#include <sys/types.h>
#include <semaphore.h>
#include <errno.h>

extern int errno;

void initsem(sem_t *,const unsigned int);
void p(sem_t *);
void v(sem_t *);
int getsemvalue(sem_t *);
void destroysem(sem_t *);
