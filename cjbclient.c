#include <sys/types.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

char server[] = "www.cjb.net";
int port = 80;
char cgiscript[] = "/cgi-bin/dynip.cgi";
char buf[500];

int openhost(char *host,int port) {
   int sock;
   struct sockaddr_in addr;
   struct hostent *he;

   he=gethostbyname(host);

   if (he==NULL) {
      perror("gethostbyname()");
      exit(-1); }

    sock=socket(AF_INET, SOCK_STREAM, getprotobyname("tcp")->p_proto);

    if (sock==-1) {
       perror("socket()");
       exit(-1); }

    memcpy(&addr.sin_addr, he->h_addr, he->h_length);
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
       perror("connect()");
       exit(-1); }

    return sock;
}

void sends(int sock,char *buf) {
  write(sock,buf,strlen(buf));
}

main(int argc, char *argv[])
{
 int sock,i;
 if (argc<3) {
    printf("\n\t\tCJB Ip Forwarding client by wC (version 1.0b)\n\n");
    printf("Sintaxe: %s <username> <password> [url (offline)]\n",argv[0]);
    printf("Send flamez to wildcoyote@hackers-pt.org, Enjoy...\n\n");
 }
 else
    if (argc==3) {
       printf("CJB Ip Forwarding client by wC (version 1.0b)\n\n");
       printf("Connecting to server... (%s)\n",server);
       sock=openhost(server,port);
       if (sock!=-1) {
           sprintf(buf,"GET %s?username=%s&password=%s\n",cgiscript,argv[1],argv[2]);
           sends(sock,buf);
           close(sock);
           printf("Done...%s.cjb.net is now forwarding to your ip!\n\n",argv[1]); }
       else printf("\nCould not connect to server :/\n\n"); }
    else {
       printf("CJB Ip Forwarding Client by wC (version 1.0b)\n\n");
       printf("Connecting to server... (%s)\n",server);
       sock=openhost(server,port);
       if (sock!=-1) {
           sprintf(buf,"GET %s?username=%s&password=%s&url=%s\n",cgiscript,argv[1],argv[2],argv[3]);
           sends(sock,buf);
           close(sock);
           printf("Account: %s.cjb.net\n",argv[1]);
           printf("Forwarding to: %s\n",argv[3]);
           printf("Done!\n\n"); }
       else printf("\nCould not connect to server :/\n\n"); }
}
