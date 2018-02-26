CC=gcc
CFLAGS=-I clang -W -Wall -Werror
hello: helloClient helloServer

helloClient: hello_client.o
	$(CC) -o helloClient hello_client.c $(CFLAGS)

helloServer: hello_server.o
	$(CC) -o helloServer hello_server.c $(CFLAGS)

	