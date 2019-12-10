#include"my.h"
#define NUM_THREADS 4
void hello(void *t){
	pthread_t my_tid;
	my_tid=pthread_self();
	printf("\tThread %d:mytid is %lx,Hello World\n",t,my_tid);
	int sum=0;
	for(int i=0;i<100;i++){
		sum+=i;
	}
	printf("SUM=%d,pid=%d,ppid=%d\n",sum,getpid(),getppid());
}
int main(){
	pthread_t  tid;
	int rv,t;
	for(t=0;t<NUM_THREADS;t++){
		rv=pthread_create(&tid,NULL,(void*(*)())hello,(void*)t);
		if(rv!=0){
			printf("thread creat failed!\n");
			return -1;
		}
		printf("creat thread %lx\n",tid);
	}
	printf("Good bye!\n");
	pthread_exit(NULL);
}
