#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>

int main  (int argc, char *argv[])
{
  char buffer[MAX_CANON];
  char *c;
  int i;
  int n;
  pid_t childpid;


  if ( (argc != 2) || ((n = atoi(argv[1])) <= 0) ) {
    fprintf (stderr, "Usage: %s number_of_processes\n", argv[0]);
    exit(1);
  }

  //spawn n - 1 processes
  for (i = 1; i < n;  ++i)
    if (childpid = fork())
      break;
  
  sprintf(buffer,
	  "i:%d  process ID:%ld  parent ID:%ld  child ID:%ld\n",
	  i, (long)getpid(), (long)getppid(), (long)childpid);
  
  c = buffer;
  
  /*****************start of critical section ********************/
  while (*c != '\0') {
    sleep(1);      
    fputc(*c, stderr);
    c++;
  }
  fputc('\n', stderr);
  /*******************end of critical section ********************/
  

  //wait for child processes to finish
  while (!(-1 == wait (NULL) && errno == ECHILD));

}
