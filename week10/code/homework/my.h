#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<wait.h>
#include <fcntl.h>
FILE* openFile();
int writeFile(FILE* fd);
