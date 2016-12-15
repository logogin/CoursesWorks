/*FIFO First Schema*/
#include <stdio.h>
int main()
{
	pid_t pid=getpid();
	int fd[2], nbytes;
	char readbuffer;
	int i=0;

	pipe(fd)
	printf("\nParent Procces PID=%d"
	" PPID=%d\n",getpid(),getppid());
	while (pid&&i<3)
	{
		pid =fork();
		if (pid==-1)
		{
			printf("Fork  %d filed!!!\n",i+1);
			exit(1);
		}
		if (pid)
			i++;
		else
		{
			printf("\nChild Procces number %d PID=%d"
			" PPID=%d\n",i+1,getpid(),getppid());
			close(fd[1]);
			nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		}
	}
	close(fd[0]);
    write(fd[1],'\x0',1);

	printf("\nEnd of Process PID=%d PPID=%d\n",getpid(),getppid());
	return 0;
}
