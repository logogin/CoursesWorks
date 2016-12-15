#include <stdio.h>
int main()
{
	pid_t pid=0;
	static int i=0;
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
			printf("\nChild Procces number %d PID=%d"
			" PPID=%d\n",++i,getpid(),getppid());
	}
	wait();
	return 0;
}
