#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1


char *readFileVarLength(const char *fname){
    printf("reading file: %s \n",fname);

    //getting the file pointer
    FILE *fp;
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Error opening the file %s\n", fname);
        exit(FAILURE);
    }


    //reading the file and string into bufff, which keeps realloc'inc itself until file is read
    int c;
    int nch = 0;
    int size = 512;
    char *buff = malloc(size);
    if(buff == NULL){
        fprintf(stderr, "out of memory\n");
        exit(FAILURE);
    }

    while((c = getc(fp)) != EOF){
        if(nch >= size-1){
            /* time to make it bigger */
            size *= 2;
            buff = realloc(buff, size);
            if(buff == NULL){
                fprintf(stderr, "out of memory\n");
                exit(FAILURE);
            }
        }
        printf("reading character: %d\n", c);
        buff[nch++] = c;
    }
    //sanitation;)
    fclose(fp);
    //seeing the contents of buffer (just a test)
    /*for(int i = 0; i < size; i++){
        printf("buffer content %d: %d\n",i,buff[i]);
    }*/
    return buff;
}


int main(int argc, const char * argv[]){
    //printf("reading file: %s \n",argv[1]);
    //const char *fname = argv[1];
    char *code = readFileVarLength(argv[1]);

    printf("reading code: %s \n",code);




    //good practice
    free(code);

    return SUCCESS;
}