/**
 * File: signal_alarm.c
 * Modified by: Holly Raetz
 * 
 * Brief summary of program:
 * Sends SIGALRM after 5s, then handles.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_sigalrm() {
    printf("Received an alarm! Exiting now...\n");
    exit(1);
}

int main() {
    signal(SIGALRM, handle_sigalrm);

    for(int i = 0; i < 5; i++)
    {
        printf("%d\n", i+1);
        sleep(1);
    }
    kill(getpid(), SIGALRM);
    return 0;
}