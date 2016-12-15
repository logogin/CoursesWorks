#include <stdio.h>
int main()
{
        pid_t pid=getpid();
        int i=0;
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
                        printf("\nChild Procces number %d PID=%d"
                " PPID=%d\n",i+1,getpid(),getppid());
        }
        if (pid)
                printf("\nParent Procces PID=%d"
                " PPID=%d\n",getpid(),getppid());
        return 0;
}