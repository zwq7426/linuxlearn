#include<stdio.h>
#include<unistd.h>
int main(){
	printf("pid=%d		ppid=%d",getpid(),getppid());
	system("/home/rlk/newpro/week9/code/test1/test1");
	printf("\n");
	printf("after system\n");
}
