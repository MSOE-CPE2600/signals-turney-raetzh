CFLAGS=-c -g -Wall -Werror
CC=gcc

all: signal_handler signal_segfault signal_sigaction signal_alarm send_signal recv_signal

signal_handler: signal_handler.o
	$(CC) -o handler signal_handler.o

signal_segfault: signal_segfault.o
	$(CC) -o segfault signal_segfault.o

signal_sigaction: signal_sigaction.o
	$(CC) -o sigaction signal_sigaction.o

signal_alarm: signal_alarm.o
	$(CC) -o alarm signal_alarm.o

send_signal: send_signal.o
	$(CC) -o send send_signal.o

recv_signal: recv_signal.o
	$(CC) -o recv recv_signal.o

clean:
	rm -f *.o signal_handler signal_segfault signal_sigaction signal_alarm send_signal recv_signal

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

