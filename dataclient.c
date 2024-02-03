#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO1_NAME "Server_fifo"
#define FIFO2_NAME "Client_fifo"
int main()
{
char p[100],f[100],c[300];
 int num,num2,fl,fd,fd2;
 mknod(FIFO1_NAME, S_IFIFO | 0666, 0);
 mknod(FIFO2_NAME, S_IFIFO | 0666, 0);
 printf("\nWaiting for SERVER...\n");
 fd = open(FIFO1_NAME, O_WRONLY);
 printf("\nSERVER Online!\nClient: Enter the path\n");
 while (gets(p) , !feof(stdin)) 
{
if ((num = write(fd, p, strlen(p))) == -1)
perror("write error\n");
else
{
printf("Waiting for reply...\n");
fd2 =open(FIFO2_NAME , O_RDONLY);
if((num2=read(fd2,c,300))==-1)
perror("Transfer error!\n");
else
{
printf("File recieved! Displaying the contents:\n\n");
if(fputs(c,stdout)==EOF)
perror("print error\n");
exit(1);
}
 }
}
return 1;
}
