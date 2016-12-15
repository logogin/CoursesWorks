#include <stdio.h>
int main()
{
	pid_t pid=getpid();
	int i=0;
	int var=0;
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
				var+=10;
				printf("Increasing value of var in this Process to %d\n",var);
			}
		}
	}
	if (pid)
	{
		printf("\nParent Procces PID=%d"
		" PPID=%d\n",getpid(),getppid());
		printf("Value of var from this Process %d\n",var);
	}
	return 0;
}
