#include"/home/rlk/linuxprogram/week6/code/staticlib/myhead.h"
#include<stdio.h>
#define NUMBER 5
int main() {
	int i[NUMBER];
	urand(i,NUMBER);
	show(i,NUMBER);
	printf("MAX=%d",max(i,NUMBER));
	printf("SUM=%d",sum(i,NUMBER));
	return 0;
}
