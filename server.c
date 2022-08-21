#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);

int main () {
   printf("Server Pid is : %d\n",getpid());
   signal(SIGUSR1, sighandler);
   signal(SIGUSR2, sighandler);

   while(1) {
      //printf("Going to sleep for a second...\n");
      sleep(1); 
   }
   return(0);
}

void sighandler(int signum) 
{
   //printf("Caught signal %d, coming out...\n", signum);
   static int i;
   int n ;
   static char ch;
   
   //static char *string = malloc(sizeof(char));
   if(!i)
   i = 0;
   n = 0;
   if (signum == SIGUSR1)
   {
      ch = (ch << 1) | 1 ;
   }
   else if(signum == SIGUSR2)
   {
      ch <<= 1;//= (ch << 0)  ;
   }
   i++;
   if(i % 8  == 0)
     {
      
      write(1,&ch,1);
      //string[i++] = ch;
      ch=0;
     }
   //ft_putstr_fd(&string,1);
}