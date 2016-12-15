#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "pv.h"

#define readers_num 3
#define allowed 3
#define max_access_time 3

key_t main_semid;
key_t counter_semid;
key_t writer_semid;
int main_mutex;
int counter_mutex;
int writer_mutex;
int times[readers_num+1]={2,1,2,3};

void init_semaphores(void)
{
	main_semid=ftok("..",125);
	counter_semid=ftok("..",126);
	writer_semid=ftok("..",127);
	main_mutex=initsem(main_semid);
	counter_mutex=initsem(counter_semid);
	writer_mutex=initsem(writer_semid);
}

void use_dbase(const int index)
{
	int sleep_time=1+rand()%max_access_time;
	printf(readers_num!=index ? "Reader %d" : "Writer"
		" uses Data Base for %d min ...\n",index+1,sleep_time);
	sleep(sleep_time);
}

void read_data(const int index)
{
	printf("Reader %d try to get into ...\n",index+1);
	p(main_mutex);
	v(counter_mutex);
	if (getsemvalue(counter_mutex)==1)
		p(write_mutex);
	v(main_mutex);
	printf("Reader %d have access\n",index+1);
	use_dbase(index);
	p(main_mutex);
	p(counter_mutex);
	if (getsemvalue(counter_mutex)==0)
		v(write_mutex);
	v(main_mutex);
	printf("Reader %d used Data Base\n",index+1);
}

void write_data()
{
	printf("Writer try to get into ...\n");
	p(write_mutex);
	printf("Writer have access\n");
	use_dbase(readers_num);
	v(write_mutex);
	printf("Writer used Data Base\n");
}

void init_procceses(void)
{
	pid_t pid=getpid();
	int i=0;
	p(main_mutex);
	while(pid&&i<(readers_num+1))
	{
		pid=fork();
		if (pid<0)
		{
			perror("Fork %d filed!!!",i+1);
			exit(1);
		}
		if (pid)
			i++;
		else
		{
			printf("Child Procces %d PID=%d PPID=%d\n",i+1,getpid(),getppid());
			p(main_mutex);
			printf("Start of "
				readers_num!=index ? "Reader %d" : "Writer""\n"i+1);
			v(main_mutex);
			while(times[i]>0)
			{
				if (i==readers_num)
					write_data();
				else
					read_data(i);
				times[i]--;
			}
		}
	}
	if (pid)
	{
		printf("Daddy arrived\n");
		v(main_mutex);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	return 0;
}