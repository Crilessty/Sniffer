#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h> 
#include<string.h>
#include<ctype.h>
#include<netdb.h>
#include<sys/file.h>
#include<sys/time.h>
#include<sys/ioctl.h>
#include<sys/signal.h>
#include<net/if.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<netinet/tcp.h>
#include<netinet/if_ether.h>
#include<unistd.h>

int openintf(char *);
int read_tcp(int );
int filter(void );
int print_header(void);
int print_data(int ,char * );
char *  hostlookup(unsigned long int);
void clear_victim(void);
void cleanup(void);
