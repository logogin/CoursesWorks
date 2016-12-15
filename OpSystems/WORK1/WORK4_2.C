#include <stdio.h>
int main()
{
	pid_t pid=0;
	pid_t father=getpid();
	int i=0;
	int var=0;
	printf("\nParent Procces PID=%d"
		" PPID=%d\n",getpid(),getppid());
	printf("Value of var from this Process %d\n",i);
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
			if (i==1)
			{
				var+=10;
				printf("Increasing value of var to in this Process to %d\n",var);
			}
		}
	}
	wait();
	if (getpid()==father)
		printf("Value of var from Parent Process %d\n",var);
	return 0;
}
