#include <stdio.h>
int main()
{
	pid_t pid=getpid();
	pid_t father=pid;
	int fd[2], nbytes;
	char string[] = "Hello, Father!";
	char readbuffer[80]="Hell";
	int i=0;
	pipe(fd);

	printf("String in Father Process '%s' \n",readbuffer);
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
			if (i==1)
			{
                close(fd[0]);
                write(fd[1], string, strlen(string));
				printf("Sending string '%s' from this Process\n",string);
			}
		}
	}
	if (pid)
	{
		close(fd[1]);
        nbytes = read(fd[0], readbuffer, sizeof(readbuffer));

		printf("\nParent Procces PID=%d"
		" PPID=%d\n",getpid(),getppid());
		printf("Resived string from Child Process '%s' \n",readbuffer);
	}
	return 0;
}
