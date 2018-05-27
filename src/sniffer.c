#include "../include/sniffer.h"
struct etherpacket
{
    struct ethhdr eth;
    struct iphdr ip;
    struct tcphdr tcp;
    char buff[8192];
}ep;

struct 
{
    unsigned long saddr;
    unsigned long daddr;
    unsigned short sport;
    unsigned short dport;
    int bytes_read;
    char active;
    time_t start_time;
}victim;

struct iphdr *ip;
struct tcphdr *tcp;
int s;
FILE *fp;

#define CAPTLEN 512
#define TIMEOUT 30
#define TCPLOG "tcp.long"

int openintf(char *d)
{
    int fd;
    struct ifreq ifr;
    int s;
    fd = socket(AF_INET,SOCK_PACKET,htons(0x800));
    if(fd<0)
    {
        perror("can't get SOCK_PACKET socket "); 
        exit(0);
    }
    strcpy(ifr.ifr_name,d);
    s = ioctl(fd,SIOCGIFFLAGS,&ifr); //获取接口标志
    if(s<0)
    {
        close(fd);
        perror("can't get flags ");
        exit(0);
    }
    ifr.ifr_flags |= IFF_PROMISC;
    s = ioctl(fd,SIOCSIFFLAGS,&ifr); //设置接口标志
    if(s<0)
        perror("can't set promiscuous mode ");
    return fd;
}

int read_tcp(int s)
{
    int x;
    while(1)
    {
        x = read(s,(struct etherpacket *)&ep, sizeof(ep));
        if(x>1)
        {
            if(filter() == 0)
                continue;
            x = x-54;
            if(x<1)
                continue;
            return x;
        }
    }
}

int filter(void)
{
    int p;
    p = 0;
    if(ip->protocol != 6)
        return 0;
    if(victim.active != 0)
    {
        if(victim.bytes_read > CAPTLEN)
        {
            fprintf(fp,"\n-- -- - [CAPLEN Exceeded]\n");
            clear_victim();
            return 0;
        }
    }
    if(victim.active )
}

int main()
{
    return 0;
}