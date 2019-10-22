#include"/home/rlk/linuxprogram/week6/code/dynamiclib/myhead.h"
#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#define NUMBER 5
int main(){
	int a[NUMBER];
	
	void *hd;
 	char *error;
	void(*f1)(),(*furand)();
	int (*f2)(),(*f3)();
	hd=dlopen("/home/rlk/linuxprogram/week6/code/dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	furand=dlsym(hd,"urand");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	furand(a,NUMBER);
	f1=dlsym(hd,"show");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f2=dlsym(hd,"max");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f3=dlsym(hd,"sum");
	if((error=dlerror())!=NULL){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	f1(a,NUMBER);
	printf("    max=%d\n",f2(a,NUMBER));
	printf("    sum=%d\n",f3(a,NUMBER));
	if(dlclose(hd)<0){
		fprintf(stderr,"%s\n",dlerror());
		exit(1);
	}
	return 0;
}
