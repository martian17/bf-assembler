#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1
#define BFCHARS(EXP) EXP == 43 || \
EXP == 44 || \
EXP == 45 || \
EXP == 46 || \
EXP == 60 || \
EXP == 62 || \
EXP == 91 || \
EXP == 93

int main(int argc, char * argv[]){
    char line[10];
    line[0] = 60;
    printf("%s\n",line);
    int i = 60;
    if(BFCHARS(line[0])){
	printf("success\n");
    }else{
	printf("failure\n");
    }
    exit(SUCCESS);
}
