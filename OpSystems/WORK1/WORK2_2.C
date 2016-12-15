/*FIFO Second Schema*/
#include <stdio.h>
int main()
{
	pid_t pid=0;
	static int i=0;
	int fd[2], nbytes;
	char readbuffer;

	pipe(fd)
	printf("\nParent Procces PID=%d"
		" PPID=%d\n",getpid(),getppid());
	while (!pid&&i<3)
	{
		pid =fork();
		if (pid==-1)
		{
			printf("Fork  %d filed!!!\n",i+1);
			exit(1);
		}
		if (!pid)
		{
			printf("\nChild Procces number %d PID=%d"
			" PPID=%d\n",++i,getpid(),getppid());
			close(fd[1]);
			nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		}
		
	}
	close(fd[0]);
    write(fd[1],'\x0',1); 
	printf("\nEnd of Process PID=%d PPID=%d\n",getpid(),getppid());
	return 0;
}
