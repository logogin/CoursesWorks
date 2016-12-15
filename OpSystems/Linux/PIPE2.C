//double pipe for bidirectional communication
//between parent <---> child

#include <unistd.h>
#include <stdio.h>

#define MSGLEN 6
#define WAITIME 3

int main ()
{
  char msg1 [] = "hello";
  char msg2 [] = "bye..";
  char buf [MSGLEN];

  int rc;
  // the communication will be implemented the following way using fd:
  // fd = {[parent_input] [child_output] [child_input] [parent_output]}
  int fd [4];

  pipe (fd);
  pipe (fd + 2);

  rc = fork ();
  if (rc < 0)
    {
      perror ("fork");
      exit (1);
    }
  else if (rc == 0) /* the child */
    {
      //close parent's file descriptors
      close (fd [0]);
      close (fd [3]);

      //recieve a message from parent and print it
      read (fd [2], buf, MSGLEN);
      printf ("child recieved: %s\n", buf);
      fflush (stdout);

      sleep (WAITIME);

      //reply to the parent
      write (fd [1], msg2, MSGLEN);
      printf ("child replied: %s\n", msg2);
      fflush (stdout);
    }
  else
    {
      close (fd [1]);
      close (fd [2]);

      sleep (WAITIME);

      //send a message to the child
      write (fd [3], msg1, MSGLEN);
      printf ("parent sent: %s\n", msg1);
      fflush (stdout);

      //get a reply and print it
      read (fd [0], buf, MSGLEN);
      printf ("parent recieved: %s\n", buf);      
      fflush (stdout);
    }
}
