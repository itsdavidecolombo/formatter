//
//  entab.c
//  
//
//  Created by Davide Colombo on 20/07/21.
//

#include <stdio.h>

#define ERROR -1

#define is_digit(c) ( (c) >= '0' && (c) <= '9') ? 1 : 0

int __atoi(const char *);

int main(int argc, char *argv[]){
    
    if(argc != 2){
        fprintf(stderr, "Usage: prog tabsize\n");
        return 1;
    }
    
    int tabsize;
    if((tabsize = __atoi(argv[1])) == ERROR){
        fprintf(stderr, "error in entab.c: invalid tabsize '%s'\n", argv[1]);
        return 2;
    }
    
    // printf("tabsize = %d\n", tabsize);
    
    int i;                              /* counter for the number of consecutive spaces */
    int c;
    while((c = getchar()) != EOF){
        if(c == ' '){
            for(i = 1; (c = getchar()) == ' '; i++)
                ;
            int tab_to_add    = i / tabsize;        /* integer division is an int */
            int blanks_to_add = i % tabsize;
            for(i = 0; i < tab_to_add; i++)
                putchar('\t');
            for(i = 0; i < blanks_to_add; i++)
                putchar(' ');
            
            if(c == EOF)
                break;                              /* exit the outer while loop if the first char after the last space is EOF */
        }
        putchar(c);
    }
    
    return 0;
}

int __atoi(const char *s){
    
    if(*s == '-')
        return ERROR;
    
    if(*s == '+')
        s++;
    
    int acc;
    for(acc = 0; is_digit(*s); s++)
        acc = acc * 10 + (*s - '0');
    
    return acc;
}
