#include <signal.h>
#include <stdio.h> 
#include <unistd.h>

void my_handler()
{
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

int main()
{
    __sighandler_t status; 

    status=signal(SIGFPE, (void *)my_handler);
    if (status == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGFPE); 

    return 0;
        
}