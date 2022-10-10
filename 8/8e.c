#include <signal.h>
#include <stdio.h> 
#include <unistd.h>
#include<sys/time.h>

void my_handler()
{
    printf("Signal SIGALRM has been caught!\n");
    _exit(0);
}

int main()
{
    __sighandler_t status; 
    struct itimerval timer;

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, 0);

    status=signal(SIGALRM, (void *)my_handler);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        while(1); 

    return 0;
        
}



   