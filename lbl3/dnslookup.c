#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netdb.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFLEN 1500

int main(int argc, char *argv[])
{
    struct addrinfo hints, *ai, *ai0;

    int i;
    char buf[BUFLEN];
    void *crrAdd;

    int loopIndex;
    if (argc < 2)
    {
        printf("Usage: %s <hostname(s)>\n", argv[0]);
        return 1;
    }

    memset(&hints, 0, sizeof(hints));
        hints.ai_family = PF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
    //Loop through domains
    for (loopIndex = 1; loopIndex < argc; loopIndex++)
    {
        // Look up the IP addresses     

        if ((i = getaddrinfo(argv[loopIndex], "5000", &hints, &ai0)) != 0)
        {
            printf("Unable to look up IP address: %s", gai_strerror(i));
            continue;
        }
        int ipFam =-1;
        

        //printing the IP strings
        for (ai = ai0; ai != NULL; ai = ai->ai_next)
        {
            //Check if IPv4/v6
            if(ai->ai_family == AF_INET)//IPv4
            {
                ipFam =4;
                crrAdd = &((struct sockaddr_in *)ai->ai_addr)->sin_addr;

            }else if (ai->ai_family == AF_INET6)//IPv6
            {
                ipFam =6;
                crrAdd = &((struct sockaddr_in6 *)ai->ai_addr)->sin6_addr;
            }
            inet_ntop(ai->ai_family, crrAdd, buf, sizeof(buf));
            // if (crrAdd == 0)
            // {
            //     printf("failed to convert address to string (errno=%d)", errno);
            //     continue; // Try the next address
            // }
            printf("%s IPv%d %s\n",argv[loopIndex],ipFam,buf);

            
        }
        //FREE THE VARS
        freeaddrinfo(ai0);
        
    }
    free(ai);
    free(ai0);
    free(crrAdd);
}