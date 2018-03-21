#include<stdio.h>
#include<sys/types.h> 
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<strings.h>

main(int argc,char * argv[]) {
	int n;
	int sock_fd;
	struct sockaddr_in servaddr;
	char buffer[100];

	if(argc!=3) {
		fprintf(stderr,"Usage error");
		exit(1);
	}

	if((sock_fd=socket(AF_INET,SOCK_DGRAM,0))<0) {
		printf("cannot create socket\n");
		exit(1);
	}

	bzero((char *)&servaddr,sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(atoi(argv[2]));
	inet_pton(AF_INET,argv[1],&servaddr.sin_addr);

	n=sendto(sock_fd,"",1,0,(struct sockaddr *)&servaddr,sizeof(servaddr));

	if (n<0) {
		printf("error sending request");
		exit(1);
	}

	if((n=recvfrom(sock_fd,buffer,sizeof(buffer),0,NULL,NULL))==-1) {
		perror("read error from server");
		exit(1);
	}
	printf("the current time is %s",buffer);
}
