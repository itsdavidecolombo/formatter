//
//  decomment.c
//  
//
//  Created by Davide Colombo on 20/07/21.
//

#include <stdio.h>

/* ================================================================================================================== */

enum status_code {WRONG_USAGE = 101, IO_ERROR, WRONG_FILE_FORMAT};

/* ================================================================================================================== */

int find(const char *, const char *);

/* ================================================================================================================== */

int main(int argc, char *argv[]){
    
    FILE *fpr;                                          /* pointer to FILE object open in read mode */
    FILE *fpw;                                          /* pointer to FILE object open in write mode */
    
    if(argc < 2){
        fprintf(stderr, "Usage: prog to_read (to_write)\n");
        return WRONG_USAGE;
    }else if(argc >= 2){
        if(find(argv[1], ".c") == WRONG_FILE_FORMAT){
            fprintf(stderr, "error in decomment.c: wrong file format in '%s'\n", argv[1]);
            return WRONG_FILE_FORMAT;
        }
        
        if((fpr = fopen(argv[1], "r")) == NULL){            /* open the first file in read mode */
            fprintf(stderr, "error in decomment.c: can't open file at '%s'\n", argv[1]);
            return IO_ERROR;
        }
        
        if(argc == 3){
            if((fpw = fopen(argv[2], "w")) == NULL){        /* open the second file in write mode */
                fprintf(stderr, "error in decomment.c: can't open file at '%s'\n", argv[1]);
                return IO_ERROR;
            }
        }else if(argc > 3){
            fprintf(stderr, "error in decomment.c: too many arguments\n");
            return WRONG_USAGE;
        }else
            fpw = stdout;                                   /* if the second (optional) argument was not passed, the write to stdout */
    }
    
    // printf("read from: %s\n", argv[1]);
    // printf("write to: %s\n", (argc == 3) ? argv[2] : "stdout");
    
    int c;
    while((c = getc(fpr)) != EOF){
        if(c == '/'){
            if((c = getc(fpr)) == '/'){
                while((c = getc(fpr)) != '\n')
                    ;
            }else if(c == '*'){
                int exit = 0;                               /* a flag for catching the closing multi-line comment */
                do{
                    while((c = getc(fpr)) != '*')           /* found an '*' but for exiting you have to found a '/' right after */
                        ;
                    if((c = getc(fpr)) == '/')              /* take the next char because the loop exit when c == '*' */
                        exit = 1;
                }while(!exit);
            }
        }else
            putc(c, fpw);
    }
    
    return 0;
}

/* ================================================================================================================== */

int find(const char *s, const char *t){
    
    int j, k;
    for(j = 0; *(s+j); j++)
        if(*(s+j) == *t)
            for(k = 0; (*(s+j) == *(t+k)); k++, j++)
                if(!*(t+k) && !*(s+j))
                    return j-k;
    return WRONG_FILE_FORMAT;
}
