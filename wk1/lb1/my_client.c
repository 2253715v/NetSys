
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#define BUFLEN 1500
int main(int argc, char *argv[])
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct addrinfo hints, *ai, *ai0;
    int i;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((i = getaddrinfo("www.google.com", "80", &hints, &ai0)) != 0)
    {
        printf("UNbale to look up IP: %s", gai_strerror(i));
    }

    connect(fd, );
    write(fd, );
    read(fd, );
    close(fd, );
}