#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
int main(int argc,char *argv[]){
	int port=atoi(argv[1]);
        struct sockaddr_in seraddr;
        int listen_fd,conn_fd;
        char buffer[10];
	struct fd_set rset,allset;
	int conn[2]={-1},convar=0;
	int nready,readvar;
	int d

        listen_fd=socket(AF_INET,SOCK_STREAM,0);
        seraddr.sin_family=AF_INET;
        seraddr.sin_port=htons(port);
        seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
	bind(listen_fd,(const struct sockaddr *)&seraddr,sizeof(seraddr));
	listen(listen_fd,2);
	
	FD_ZERO(&allset);
	FD_SET(listen_fd);
	for( ; ;){
		rset=allset;
		nready=select(4,fd_set *readset,NULL,NULL,NULL);
		if(FD_ISSET(listen_fd,&rset)){
			conn_fd=accept(listen_fd,(struct sockaddr *)NULL,NULL);
			con[++convar]=conn_fd;	
			FD_SET(conn_fd,&allset);
		}
		if (--nready<=0)
			continue;
		//init for loop
		if(FD_ISSET(conn_fdi,&rset)){ //change conn_fd to conn array
			readvar=read(conn_fd,(char *)buffer,sizeof(buffer));
		if(readvar==0)
			strcpy.(buffer,"woow");
		else
			write(conn[1],(char *)buffer,sizeof(buffer));
		}
	}
}
		
