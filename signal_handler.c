/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 */

/**
 * Modified by: Holly Raetz
 * 
 * Brief summary of modifications:
 * Program now automatically interrupts itself after 10s.
 * Program also does not exit upon interrupt.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n"); //Can still exit using ^\ in cmdline
}

int main() {

    int count = 10;
    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
        count--;
        if(count == 0)
        {
            kill(0, SIGINT);
        }
    }

    return 0;
}