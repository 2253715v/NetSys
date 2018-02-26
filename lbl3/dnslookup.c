#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>

#include <errno.h>

#include <sys/socket.h>
#include <netinet/in.h>

#define BUFLEN 1500

int main(int argc, char *argv[])
{
    struct addrinfo hints, *ai, *ai0;

    int i, fd;
    char buf[BUFLEN];
    const char *crrAdd;

    int loopIndex;
    if (argc < 2)
    {
        printf("Usage: %s <hostname(s)>\n", argv[0]);
        return 1;
    }
    //Loop through domains
    for (loopIndex = 1; loopIndex <= argc; loopIndex++)
    {
        // Look up the IP addresses
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = PF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;

        if ((i = getaddrinfo(argv[1], "80", &hints, &ai0)) != 0)
        {
            printf("Unable to look up IP address: %s", gai_strerror(i));
            continue;
        }
        //printing the IP strings
        for (ai = ai0; ai != NULL; ai = ai->ai_next)
        {
            crrAdd = inet_ntop(ai->ai_family, ai->ai_addr, buf, sizeof(buf));
            if (crrAdd == 0)
            {
                printf("failed to convert address to string (errno=%d)", errno);
                continue; // Try the next address
            }

            // Print out the address
        }
        //FREE THE VARS
    }
}