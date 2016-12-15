#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "pv.h"

#define philos_num 5
#define LEFT index==0 ? philos_num-1 : (index-1)%philos_num
#define RIGHT (index+1)%philos_num
#define THINKING 0
#define HUNGRY 1
#define EATING 2

key_t main_semkey;
key_t semkey[philos_num];
int main_mutex;
int mutex[philos_num]; 
int eating_time[philos_num];
char state[philos_num];
int fd;

void init_sem(void)
{
	int i=0;
	for (i=0; i<philos_num; i++)
	{
		semkey[i]=ftok(".",125+i);
		if ((mutex[i]=initsem(semkey[i]))<0)
			exit(1);
	}
	main_semkey=ftok(".",125+i);
	if ((main_mutex=initsem(main_semkey))<0)
		exit(1);
}

void init_file(void)
{
	fd=creat("state.dat",0666);
	if (fd<0)
		exit(1);
}

void init_state(void)
{
	int i=0;
	for (i=0; i<philos_num; i++)
		state[i]=THINKING;
}

void write_state(void)
{
	lseek(fd,0,SEEK_SET);
	write(fd,state,sizeof(state));
}

void read_state(void)
{
	lseek(fd,0,SEEK_SET);
	read(fd,state,sizeof(state));
}

void test(const int index)
{
	read_state();
	if (state[index]==HUNGRY&&state[LEFT]!=EATING&&
		state[RIGHT]!=EATING)
	{
		state[index]=EATING;
		write_state();
		v(mutex[index]);
	}
}

void take_forks(const int index)
{
	p(main_mutex);
	state[index]=HUNGRY;
	write_state();
	test(index);
	v(main_mutex);
	p(mutex[index]);
}

void put_forks(const int index)
{
	p(main_mutex);
	state[index]=THINKING;
	write_state();
	test(LEFT);
	test(RIGHT);
	v(main_mutex);
	p(mutex[index]);
}

void init_philos(void)
{
	int i=0;
	pid_t pid=getpid();
	for (i=0; i<philos_num; i++)
	{
		printf("Enter eating time for %d philosopher : ",i+1);
		scanf("%d",&eating_time[i]);
	}
	i=0;
	p(main_mutex);
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
			while (eating_time>0)
			{
				printf("Process %d try to take forks\n",i+1);
				take_forks(i);
				eating_time[i]-=5;
				printf("Process %d eated 5 min\n",i+1);
				put_forks(i);
				printf("Process %d puted forks\n",i+1);
			}
			printf("Process %d finished\n",i+1);
		}
	}
	if (pid)
	{
		int i=0;
		int status;
		printf("Daddy arrived\n");
		v(main_mutex);

		for (i=0; i<philos_num; i++)
			wait(&status);
		close(fd);
		unlink("state.dat");
	}
}

int main()
{
	init_sem();
	init_state();
	init_file();
	init_philos();
	return 0;
}
