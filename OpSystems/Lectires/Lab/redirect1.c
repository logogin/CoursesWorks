/*
Duplication of stdout descriptor to a file. It means that the ouput
of the execution is printed in the file
*/
 
#include <stdio.h>
#include <fcntl.h>
main(int argc,char * argv[])
{
 int fd1;

fd1=open(argv[1],O_CREAT|O_TRUNC|O_WRONLY,0600);
dup2(fd1,1);/*Duplicate descriptor to stdout*/
close(fd1);
execvp(argv[2],&argv[2]);
}
/*
Output:


/users/popeye/segel/gidig/OS-145->r1 k echo good evening
/users/popeye/segel/gidig/OS-146->cat k
good evening

*/
