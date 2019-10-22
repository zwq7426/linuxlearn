#include<stdio.h>
int main (int argc,char *argv[]){
	//1
	//printf("hello!"\n);


	//2	
	//for(int i=0;i<1024;i++)
		//printf("hello!");

	//3
	//printf("hello!");
	//fclose(stdout);

	//4.1
	setvbuf(stdout,NULL,_IONBF,0);
	printf("hello!");

	while(1);
	return 0;
}
