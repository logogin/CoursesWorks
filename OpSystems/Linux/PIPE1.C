//#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>

#define MSGLEN 9 /* message length */

#define BANIM 3

#define WAITIME 2 /* waiting time (secs) */

int main()

{
    int rc, i;
    int fd[2];
    char *msg[] = {"message1", "message2", "message3"};
    char buf[MSGLEN];

    //create a pipe
    pipe(fd);
    for (i = 0; i < BANIM; i++)
    {
        rc = fork();
        if (rc == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (rc == 0)
        {

            //close the input side of the pipe
            close(fd[0]);
            while (1)
            {
                //write through the pipe
                write(fd[1], msg[i], MSGLEN);

                //print message and flush the standard output
                printf("child %d sent message\n", i);
                fflush(stdout);

                //wait for a while
                sleep(WAITIME);
            }
        }
    }

    //father - close the output side of the pipe
    close(fd[1]);

    //keep reading messages and send them to stdout
    while (1)
    {
        read(fd[0], buf, MSGLEN);
        printf("father recieved message %s\n", buf);
        fflush(stdout);
    }
}
