#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#define SEPVEOPT 3333
#define BACKING 10

int main(){
	int sockfd,client_fd;
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	int sin_size;
	if((sockfd=socket(AF_INET,SOCK_STEAM,0))==-1){
		perror("socket create failed!");
		exit(1);
	}
	my_addr.sin_family=AF_INET;
	my_addr.siin_port=htons(SERVPORT);
	my_addr.sin_addr.s_addr=INADDR_ANY;
	bzero(&(my_addr.sin_zero),8);
	
	if(bind(sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))==-1){
		perror("bind error!");
		exit(1);
	}
	if(listen(sockfd,BACKLOG)==-1){
		perror("listen error");
		exit(1);
	}
	while(1){
		sin_sizeof(struct sockaddr_in)
	}
}
