 /*
 * socket programming
 *
 * a multi client echo server 
 *
 * using select for this.... sockfd and newsockfds are added to the select list to be read.... Only single process
 *													but time consuming....
 * 
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define N_THREADS 9

void commun(int newsockfd)
{
	int r,w;
	char buffer[256];
	
	if((r = read(newsockfd,buffer,255))>0){
		printf("%s\n",buffer);
		w = write(newsockfd,buffer,r);
		if(w<0){
			perror("Error in writing");
			return;
		}
	}
	if(r<0){
		perror("Error reading messages");
		return;
	}
}

int main(int argc,char * argv[])
{
	int pid,sockfd,newsockfd,portno,n, k=0,cli_len,i,j;
	struct sockaddr_in serv_addr,cli_addr;
	int max_descriptor;
	fd_set sockset,readfds;
	long timeout;
	struct timeval settimeout;
	if(argc<2){
		fprintf(stderr,"Give the portnumber\n");
		exit(1);
	}
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
	FD_ZERO(&sockset);
	FD_ZERO(&readfds);
	FD_SET(sockfd,&sockset);
	//settimeout.tv_sec = 5;
	//settimeout.tv_usec = 0;
	max_descriptor = sockfd;
	while(1){
		readfds = sockset;
		if(select(max_descriptor+1,&readfds,NULL,NULL,NULL)==0){
			perror("error in selecting");
			exit(1);
		}
		for(i=0;i<=max_descriptor;i++){
			if(FD_ISSET(i,&readfds)){
				if(i==sockfd){
					newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,(socklen_t *)&cli_len);
					if(newsockfd<0){
						perror("Error in accepting");
					}else{
						FD_SET(newsockfd,&sockset);
						if(newsockfd > max_descriptor){
							max_descriptor = newsockfd;
						}
						k++;
						printf("%d\n",k);
					}
				}else{
					commun(i);
				}
			}
		}
	}
	for(i=0;i<max_descriptor;i++){
		FD_CLR(i,&sockset);
	}
	close(sockfd);
	return 0;
}
