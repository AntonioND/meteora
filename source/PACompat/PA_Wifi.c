
#include <PA9.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int PA_InitSocket(int *sock, char *host, int port, int mode)
{
    unsigned long ip;
    struct sockaddr_in servaddr;

    *sock = socket(AF_INET, SOCK_STREAM, 0);
    ip = *(unsigned long *)gethostbyname(host)->h_addr_list[0];

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = ip;

    if (mode == PA_NONBLOCKING_TCP)
    {
        if (connect(*sock, (struct sockaddr *) &servaddr, sizeof(servaddr)) == 0)
        {
            int i = 1;
            ioctl(*sock, FIONBIO, &i);
            return 1;
        }
    }

    return 0;
}
