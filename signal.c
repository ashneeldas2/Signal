#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void sighandler(int signo) {
    if (signo == SIGINT) {
        printf("I've been interrupted!! oh no!!!\n");
        exit(1);
    }

    if (signo == SIGUSR1) {
        printf("The parent process number is: %d\n", getppid());
    }
}

int main() {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while (1) {
        printf("The process number is: %d\n", getpid());
        sleep(1);
    }
    return 0;
}