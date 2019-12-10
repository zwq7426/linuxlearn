#include<pthread.h>
#include<stdio.h>
void *creat(void *arg){
	printf("new thread created......");
}
int main(int argc,char *argv[]){
	pthread_t tidp;	
	int error;
	error=pthread_create(&tidp,NULL,create,NULL);
	if(error!=0){
		printf("pthread_create is not created...");
		return -1;
	}
	printf("prthread_create is crreated...");
	return 0;	
}
