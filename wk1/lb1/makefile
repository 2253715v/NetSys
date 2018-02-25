TARGET = prog
LIBS = -lm
CC = gcc
CFLAGS = -W -Wall -Werror -o

make: helloClient helloServer 

helloClient	:
	$(CC) $(CFLAGS) helloClient hello_client.c

helloServer	:
	$(CC) $(CFLAGS) helloServer hello_server.c