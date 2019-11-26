#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
int count =0;
int main(){
	printf("before fork(), pid = %d\n", getppid());
	pid_t p1,p2,p3;
	printf("parent fork first time!\n");
	p1=fork();
	int s1,s2,s3,r1,r2,r3;
	if(p1<0){
		perror("fork1 failed!\n");
		return -1;
	}		
	else if(p1==0){
		count+=1;
		printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
		exit(99);
	}
	else{
		printf("parent fork second time!\n");
		p2=fork();
		if(p2<0){
			perror("fork2 failed!\n");
			return -1;	
		}
		else if(p2==0){
			count+=1;
			printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
			exit(34);
		}
 		else{
			printf("parent fork third time!\n");
			p3=fork();
			if(p3<0){
				perror("fork3 failed!\n");
				return -1;
			}
			else if(p3==0){
				count+=1;
				printf("child pid=%d,ppid=%d,count=%d\n",getpid(),getppid(),count);
				exit(77);
			}
			else{
				printf("parent waiting\n");
				r1=wait(&s1);
				r2=wait(&s2);
				r3=wait(&s3);
				printf("r1=%d,s1=%d,r2=%d,s2=%d,r3=%d,s3=%d\n",r1,WEXITSTATUS(s1),r2,WEXITSTATUS(s2),r3,WEXITSTATUS(s3));
				printf("parent pid=%d,count=%d\n",getppid(),count);
				return 0;
			}
		}
	}
}



	/*int pipe[2];
	pid_t fpid;
	int num=1;
	printf("We will creat three clildren\n");'
	printf("before fork(), pid = %d\n", fpid);*/
	/*for(int i=0;i<3;i++){
			fpid=fork();
        if(fpid<0)
                printf("error\n");
        else if(fpid==0){
        	printf("i am progress%d! childpid=%d parentpid=%d\n",num,getpid(),getppid());
			num++;
        }
        else{
        	break;//返回值为大于0的进程是父进程，判断如果此进程是父进程就跳出循环     
		}
	}*/
