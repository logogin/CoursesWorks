#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pv.h"

#define philos_num 5
#define LEFT index==0 ? philos_num-1 : (index-1)%philos_num
#define RIGHT (index+1)%philos_num
#define EATER1 (index+2)%philos_num
#define EATER2 (index+3)%philos_num

key_t main_semkey;
key_t semkey[philos_num];
int main_mutex;
int mutex[philos_num];
int eating_time[philos_num];

void init_semaphores(void)
{
	int i=0;
	for (i=0; i<philos_num; i++)
	{
		semkey[i]=ftok("..",125+i);
		mutex[i]=initsem(semkey[i]);
	}
	main_semkey=ftok("..",125+i);
	main_mutex=initsem(main_semkey);

/*	printf("%d ",getsemvalue(main_mutex));
	for (i=0; i<philos_num; i++)
		printf("%d ",getsemvalue(mutex[i]));
	puts("");
	p(main_mutex);
	printf("%d ",getsemvalue(main_mutex));
	for (i=0; i<philos_num; i++)
		printf("%d ",getsemvalue(mutex[i]));
	puts("");
	v(main_mutex);
	printf("%d ",getsemvalue(main_mutex));
	for (i=0; i<philos_num; i++)
		printf("%d ",getsemvalue(mutex[i]));
	puts("");*/
}

/*void destroy_semaphores(void)
{
	int i=0;
	for (i=0; i<philos_num; i++)
		destroysem(&mutex[i]);
	destroysem(&main_mutex);
}*/

void take_forks(const int index)
{
	//printf("try 'p(&main_mutex)'\n");

int i=0;	

	//printf("passed 'p(&main_mutex)'\n");
	//printf("try 'p(&mutex[index])'\n");
	printf("main=%d ",getsemvalue(main_mutex));
	for (i=0; i<philos_num; i++)
		printf("%d=%d ",i,getsemvalue(mutex[i]));
	puts("");
	p(mutex[index]);

	p(main_mutex);
	//printf("passed 'p(&mutex[index])'\n");

	
	if (getsemvalue(mutex[LEFT])>0)
	{
	//	printf("try 'p(&mutex[LEFT])'\n");
		p(mutex[LEFT]);
	//	printf("passed 'p(&mutex[LEFT])'\n");
	}
	if (getsemvalue(mutex[RIGHT])>0)
	{
	//	printf("try 'p(&mutex[RIGHT])'\n");
		p(mutex[RIGHT]);
	//	printf("passed 'p(&mutex[RIGHT])'\n");
	}
	v(main_mutex);
}

void put_forks(const int index)
{
	//printf("try 'p(&main_mutex)'\n");
//	p(main_mutex);
	v(mutex[index]);
	//printf("passed 'p(&main_mutex)'\n");
	if (getsemvalue(mutex[EATER1])>0)
		if (getsemvalue(mutex[RIGHT])==0)
			v(mutex[RIGHT]);
	if (getsemvalue(mutex[EATER2])>0)
		if (getsemvalue(mutex[LEFT])==0)
			v(mutex[LEFT]);
	
//	v(main_mutex);
}

void init_philos(void)
{
	int i=0;
	int j=0;
	pid_t pid=getpid();
	/*printf("%d ",getsemvalue(main_mutex));
	for (j=0; j<philos_num; j++)
		printf("%d ",getsemvalue(mutex[j]));
	puts("");*/

	for (i=0; i<philos_num; i++)
	{

		/*printf("%d ",getsemvalue(main_mutex));
		for (j=0; j<philos_num; j++)
			printf("%d ",getsemvalue(mutex[j]));
		puts("");*/

		printf("Enter eating time for %d philosopher : ",i+1);
		scanf("%d",&eating_time[i]);
	}
	i=0;
	/*printf("try 'p(&main_mutex)'\n");

	printf("%d ",getsemvalue(main_mutex));
	for (j=0; j<philos_num; j++)
		printf("%d ",getsemvalue(mutex[j]));
	puts("");*/

	p(main_mutex);
	
	/*printf("%d ",getsemvalue(main_mutex));
	for (j=0; j<philos_num; j++)
		printf("%d ",getsemvalue(mutex[j]));
	puts("");
	
	printf("passed 'p(&main_mutex)'\n");*/
	while (i<philos_num&&pid)
	{
		pid=fork();
		if (pid<0)
		{
			printf("Fork %d filed !!!\n",i+1);
			exit(1);
		}
		if (pid)
			i++;
		else
		{
			
			printf("Child Process %d PID=%d"
				" PPID=%d\n",i+1,getpid(),getppid());
			p(main_mutex);
			printf("Start of Process %d\n",i+1);
			v(main_mutex);
			while (eating_time[i]>0)
			{
				printf("Process %d try to take forks\n",i+1);
				take_forks(i);
				eating_time[i]-=5;
				printf("Process %d eating 5 min ...\n",i+1);
				sleep(2);
				put_forks(i);
				printf("Time left for process %d is %d\n",i+1,eating_time[i]);
				printf("Process %d puted forks\n",i+1);
			}
			printf("Process %d finished\n",i+1);
		}
	}
	if (pid)
	{
		printf("Daddy arrived\n");
		v(main_mutex);
	}
}

int main(int argn,char **argv)
{
	init_semaphores();
	init_philos();
	return 0;
}
