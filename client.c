#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void send_char(int pid, char x)
{
    int i;
    i = 0;
    while(i <= 7)
    {
        if( (x<<i) & 128)
        {
            kill(pid,SIGUSR1);
            // printf("1");
        }
        else{
            kill(pid,SIGUSR2);
             // printf("0");
        }
        i++;
        usleep(2500);
    }
}

int main(int ARGC,char **ARGV)
{
    int n;
    int pid = atoi(ARGV[1]);//ARGC[1];

    n = 0;
    if(!pid || !ARGV[2]  ||  pid < 100) //error handling incase passed empty PID or no string
    {
        printf("Error\n");
        return 0;
    }
    while (ARGV[2][n])
    {
        send_char(pid, ARGV[2][n]); 
        n++;  
    }
    return(0);
}