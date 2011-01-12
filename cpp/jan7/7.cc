/*
 * simple thread programming
 */

#include <iostream>
#include <stdio.h>
#include <pthread.h>

using namespace std;

void * print(void * n)
{
	int * p;
	p = (int *)n;
	cout<<"I am thread : "<<*p<<endl;
	pthread_exit(NULL);
}

int main()
{
	pthread_t t_arr[5];
	for(int i=0;i<5;i++){
		cout<<"creating thread : "<<i<<endl;
		pthread_create(&t_arr[i],0,print,(void *)&i);
	}
	for(int i=0;i<5;i++){
		pthread_join(t_arr[i],NULL);
	}
	return 0;
}
