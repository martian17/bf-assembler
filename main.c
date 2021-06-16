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
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(FAILURE);
    }
    char *fname = argv[1];
    printf("reading file: %s \n",fname);

    //getting the file pointer
    FILE *fp;
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Error opening the file %s\n", fname);
        exit(FAILURE);
    }
    
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    
    int ln = 0;
    while ((nread = getline(&line, &len, fp)) != -1) {
        printf("Retrieved line of length %zu:\n", nread);
        fwrite(line, nread, 1, stdout);
        //printf("%s\n",line);
        //debug code. Looks like we have buffer overflow here, if we use printf at least.
        //getline() does not give you null terminated string
        // Null Terminater ~The Void Incursion~
        if(++ln == 50)printf("******%d, %d, %d, %d\n",line[0],line[1],line[2],line[3]);
        
        
        // all right, now we can do fun things with the line we got!
        for(int i = 0; i < len; i++){
            if(line[i] == 32 || line[i] == 9){
                //eat away spaces
            }else if(BFCHARS(line[i])){
                //brainfuck characters
                for(i; i < len; i++){
                    if(BFCHARS(line[i])){
                        //strcat
                    }else if(line[i] == 47  && i < len-1 && line[i+1] == 47){//comment
                        
                    }
                }
            }else{
                break; // do nothing to the line
            }
        }
    }

    free(line);
    fclose(fp);
    exit(SUCCESS);
//
    
    /*
    char * strBuff[10];
    int size = 10;
    while(getline(strBuff, &len, fp)){
        printf("got output: %s \n",strBuff);
    }
    */
}


/*
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
            / time to make it bigger /
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
    /for(int i = 0; i < size; i++){
        printf("buffer content %d: %d\n",i,buff[i]);
    }/
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
}*/
