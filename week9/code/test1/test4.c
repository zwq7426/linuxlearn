#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t result;
	result=fork();
	int newret;
	if(result==-1){
		perror("creat fail");
		exit;	
	}
	else if(result==0){
		printf("返回值是：%d，说明这是子进程！\n此进程的进程号(PID)是：%d\n此进程的父进程的进程号(PPID)是：%d\n",result,getpid(),getppid());
		newret=system("ls -l");
	}
	else{
		sleep(10);
	}
		printf("返回值是：%d，说明这是父进程！\n此进程的进程号(PID)是：%d\n此进程的父进程的进程号(PPID)是：%d\n",result,getpid(),getppid());
}
