#include"my.h"
FILE* openFile(){
	FILE *fp;
        fp=fopen("file.dat","w+");
	return fp;
}
int writeFile(FILE* fp){
	char buf[]={"0 1 2 3 4 5 \n"};
	/*fp=fopen("file.dat","a+");*/
    if(fp==NULL){
		perror("failed to open file!\n");
		return -1;
    }
	printf("open file success.\n");
	int count = strlen(buf);
	fwrite(buf,count,1,fp);
	return 0;
}
