/*
 * socket programming
 *
 * a simple echo server in c++
 * 
 */

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(int argc,char * argv[])
{
	int pid,sockfd,newsockfd,portno,n,cli_len;
	struct sockaddr_in serv_addr,cli_addr;
	char buffer[256];
	if(argc<2){
		fprintf(stderr,"Give the portnumber\n");
		exit(1);
	}
	bzero(buffer,sizeof(buffer));
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	if(sockfd<0){
		perror("Error opening socket");
		exit(1);
	}
	bzero((char*)&serv_addr,sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr))<0){
		perror("Error on binding");
		exit(1);
	}
	listen(sockfd,5);
	bzero((char *)&cli_addr,sizeof(cli_addr));
	cli_len = sizeof(cli_addr);
	newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,(socklen_t *)&cli_len);
	if(newsockfd<0){
		perror("Error in accepting");
		exit(1);
	}
	close(sockfd);
	while(1){
		n = read(newsockfd,buffer,255);
		if(n<0){
			perror("Error reading messages");
			exit(1);
		}
		cout<<buffer<<endl;
		n = write(newsockfd,buffer,sizeof(buffer)-1);
		if(n<0){
			perror("Error in writing");
			exit(1);
		}
	}
	close(newsockfd);
	return 0;
}
