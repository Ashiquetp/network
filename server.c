#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include "reverse.c"
int main(int argc,char *argv[]){
	int port=atoi(argv[1]);
	struct sockaddr_in seraddr;
	int sd,data_socket;
	char buffer[10];
	sd=socket(AF_INET,SOCK_STREAM,0);
	seraddr.sin_family=AF_INET;
	seraddr.sin_port=htons(port);
	seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(sd,(const struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(sd,5);
	data_socket=accept(sd,(struct sockaddr *)NULL,NULL);
	read(data_socket,(char *)buffer,sizeof(buffer));
	strrev(buffer);
	write(data_socket,(char *)buffer,sizeof(buffer));
}
