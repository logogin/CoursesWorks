#include <stdio.h>
#include "pv.h"

#define Find_fork 0
#define Put_fork 1


const int philos_num=5;
int state[philos_num];
int eating_time[philos_num];
int fd[2], nbytes;
char readbuffer[2];

int mutex1;
key_t semkey = 0x200;
int mutex2;
key_t semkey = 0x300;

void write_var(const char index,const char value)
{
	char st[2]={index,value};
	close(fd[0]);
    write(fd[1], st, sizeof(st));
}


int permition(void)
{
	char acces;
	close(fd[1]);
	nbytes = read(fd[0],acces,sizeof(acces));
	if(acces == 1)
		return 1;
	else
		return 0;
}
int chek_state(void)
{
	int i;
	for(i=0;i<philo_num;i++)
	{
		if(state[i])
			return 1;
	}
	return 0;
}

void init_state(void)
{
	int i;
	for (i=0; i<philos_num; i++)
		state[i]=0;
}


void init_philos()
{
	pid_t pid=getpid();
	char i=0;
	char eat_time;
	int acces;
	while (pid&&i<philos_num)
	{
		pid=fork();
		if (pid==-1)
		{
			printf("Fork  %d filed!!!\n",i+1);
			exit(1);
		}
		if (pid)
		{
			read_var();
			i++;
					else
		{
			printf("\nChild Procces number %d PID=%d"
				" PPID=%d\n",i+1,getpid(),getppid());
			printf("Please enter eating time for %d philo",i+1);
			scanf("%d",&eat_time);
			write_var(1,i,eat_time);
			while (eat_tame>0)
			{
				p(mutex2);
				p(mutex1);
				write_var(i,Find_fork);
				acces=permition();
				v(mutex1);
				if(acces)
				{
					eating_time[i]-=5;
					printf("\nPhilo %d eating 5 minutes",i+1);
					write_var(i,Put_fork);
				}
				v(mutex2);
			}
		}
	}
	if (pid)
	{
		printf("\nParent Procces PID=%d"
			" PPID=%d\n",getpid(),getppid());
		while(chek_state())
			{
				close(fd[1]);
				nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
				if (readbuffer[1] == Find_fork)
				{
					if(readbuffer[0] == 0)
					{
						if((state[4]==0)&&(state[1]==0))
						{
							close(fd[0]);
							write(fd[1],1,1);
							eating_time[0]-=5;
							state[0] = 1;
						}
						else
						{
							close(fd[0]);
							write(fd[1],0,1);
							
						}
					}
					else
					{
						if((state[(readbuffer[0]+1)%philos_num]==0)&&(state[(readbuffer[0]-1)%philos_num]==0))
						{
							close(fd[0]);
							write(fd[1],1,1);
							eating_time[readbuffer[0]]-=5;
							state[readbuffer[0]] = 1;
						}
						else
						{
							close(fd[0]);
							write(fd[1],0,1);
							
						}
					}
				}
				else
				{
					state[readbuffer[0]] = 0;
					
				}
			}
		}
	}
}

void main()
{
	pipe(fd);

	if ((mutex1 = initsem(semkey,1)) < 0)
		exit(1); 

	if ((mutex2 = initsem(semkey,2)) < 0)
		exit(1); 

	init_state();
	init_philos();
}