//
//  formatter.c
//  
//
//  Created by Davide Colombo on 20/07/21.
//

#include <stdio.h>
#include <ctype.h>

#define ERROR -1

int __atoi(const char *);

/* ============================================================================================================== */

int main(int argc, char *argv[]){
    
    if(argc != 2){
        fprintf(stderr, "Usage: prog tabsize\n");
        return 1;
    }
    
    int n;
    if((n = __atoi(argv[1])) == ERROR){
        fprintf(stderr, "error in formatter.c: not a number\n");
        return 2;
    }
    
    int c;
    int i;
    int nspaces;
    for(i = 0; (c = getchar()) != EOF; i %= n){
        if(c == '\t'){
            for(; (i % n); i++)
                putchar(' ');
            continue;                   /* skip the rest of the code after the 'if' statement for this cycle */
        }
        putchar(c);
        i++;
    }
    
    return 0;
}

/* ============================================================================================================== */

int __atoi(const char *s){
    
    int c;
    while((c = *s) == ' ' || c == '\t')
        s++;
    
    if(isalpha(*s) || *s == '-')
        return ERROR;
    
    if(*s == '+')
        s++;
    
    int acc;
    for(acc = 0; isdigit(*s); s++)
        acc = acc * 10 + (*s - '0');
    
    // TODO: check g.t. 2e32-1
    
    return acc;
}
