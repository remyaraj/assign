/*
 * socket programming
 *
 * Multiclient echo server with fork() - maximum forking in the machine : 1690-1700
 *
 * Not complete
 * 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

void sigfun(int n)
{
	wait3(NULL,WNOHANG,NULL);
}

void communication(int newsockfd)
{
	char buffer[256];
	int n;
	bzero(buffer,sizeof(buffer));
	while((n = read(newsockfd,buffer,255))>0){
		printf("%s\n",buffer);
		n = write(newsockfd,buffer,sizeof(buffer));
		if(n<0){
			perror("Error in writing");
			exit(1);
		}
	}
}

int main(int argc,char * argv[])
{
	int pid,sockfd,newsockfd,portno,n=0,cli_len;
	struct sockaddr_in serv_addr,cli_addr;
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
	while(1){
		newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,&cli_len);
		if(newsockfd<0){
			perror("Error in accepting");
			exit(1);
		}
		pid = fork();
		if(pid<0){
			perror("Error in forking");
			exit(1);
		}
		if(pid==0){
			close(sockfd);
			communication(newsockfd);
			exit(0);
		}
		n++;
		printf("%d\n",n);
		signal(SIGCHLD,sigfun);
		close(newsockfd);
	}
	return 0;
}
