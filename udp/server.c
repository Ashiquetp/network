#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include "matrix.c"
main(int argc,char *argv[]) {
int port=atoi(argv[1]);
int sd;

//socket initialization
struct sockaddr_in server_address,client_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(port);
sd=socket(AF_INET,SOCK_DGRAM,0);

//bind socket
bind(sd,(struct sockaddr*)&server_address,sizeof(server_address));

int client_length=sizeof(client_address);

//initialise matrix
int matrix_a[10][10];
int matrix_b[10][10];
int matrix_c[10][10];
//input data to matrix




recvfrom(sd,matrix_a,sizeof(matrix_a),0,(struct sockaddr*)&client_address,&client_length);
recvfrom(sd,matrix_b,sizeof(matrix_b),0,(struct sockaddr*)&client_address,&client_length);

//calculate matrix


//send to client
sendto(sd,matrix_c,sizeof(matrix_c),0,(struct sockaddr*)&client_address,sizeof(client_address);



 
	
