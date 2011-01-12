 /*
 * socket programming
 *
 * a multi client echo server 
 *
 * To find the number of threads
 *
 * max no: of threads by the machine : 1852 - 1900
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

void * commun(void * arg)
{
	int newsockfd,r,w;
	newsockfd = (int)arg;
	char buffer[256];
	
	while((r = read(newsockfd,buffer,255))>0){
		printf("%s\n",buffer);
		w = write(newsockfd,buffer,r);
		if(w<0){
			perror("Error in writing");
			exit(1);
		}
	}
	if(r<0){
		perror("Error reading messages");
		exit(1);
	}
	close(newsockfd);
	printf("Its closed\n");
	pthread_exit(0);
}

int main(int argc,char * argv[])
{
	int pid,sockfd,newsockfd,portno,n, k=0,cli_len,i,j;
	struct sockaddr_in serv_addr,cli_addr;
	pthread_t *t_arr;
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
	while(1){
		t_arr = (pthread_t *)malloc(sizeof(pthread_t));
		bzero((char *)&cli_addr,sizeof(cli_addr));
		cli_len = sizeof(cli_addr);
		newsockfd = accept(sockfd,(struct sockaddr *)&cli_addr,(socklen_t *)&cli_len);
		if(newsockfd<0){
		perror("Error in accepting");
		exit(1);
		}
	
		n = pthread_create(t_arr,0,commun,(void *)newsockfd);
		if(n){
			printf("No:of threads = %d\n",k);
			perror("Error in creating thread ");
			exit(1);
		}
		k++;
		printf("%d\n",k);
		free(t_arr);
	}
	close(sockfd);
	return 0;
}
