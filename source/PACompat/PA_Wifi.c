
#include <PA9.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define isdigit(c) ((c) >= '0' && (c) <= '9')

#define IS_DIGIT_OR_DOT(c) (isdigit(c) || ((c) == '.'))

#define IS_INETADDR(s) \
    (IS_DIGIT_OR_DOT(s[0]) && IS_DIGIT_OR_DOT(s[1]) && \
     IS_DIGIT_OR_DOT(s[2]) && IS_DIGIT_OR_DOT(s[3]) && \
     IS_DIGIT_OR_DOT(s[4]) && IS_DIGIT_OR_DOT(s[5]) && IS_DIGIT_OR_DOT(s[6]))

static unsigned long makelong(u32 data1, u32 data2, u32 data3, u32 data4)
{
    return (data4 << 24) | (data3 << 16) | (data2 << 8) | data1;
}

static unsigned long PA_chartoip(char *message)
{
    unsigned char data[4];
    int debut = 0;

    for(int j=0;j<4;j++)
    {
        int i;
        char buffer[256];
        for (i = debut; message[i] != '.' && message[i] != '\0'; i++)
           buffer[i-debut] = message[i];

        buffer[i - debut] = '\0';
        debut = i + 1;
        data[j] = atoi(buffer);
    }

    return makelong(data[0], data[1], data[2], data[3]);
}

int PA_InitSocket(int *sock, char *host, int port, int mode)
{
    unsigned long ip;
    struct sockaddr_in servaddr;

    *sock = socket(AF_INET, SOCK_STREAM, 0);
    if (IS_INETADDR(host))
        ip = PA_chartoip(host);
    else
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
