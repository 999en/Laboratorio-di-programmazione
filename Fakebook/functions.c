#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append(struct bacheca* b, struct post p){
    if (len(b)>=MAX)
    {
        return 1;
    }

    b->deposito[b->first_in]=malloc(sizeof(struct post));
    *b->deposito[b->first_in]=p;
    b->first_in=(b->first_in + 1) % MAX;
    b->lenght++;
    return 0;
}
int len(struct bacheca* b){
    return b->lenght;
}
int is_empty(struct bacheca* b){
    if (len(b)==0)
    {
        return 1;
    } else return 0;
    
}
struct post* pop(struct bacheca* b){
    if (is_empty(b)==1)
    {
        return NULL;
    }
    
    struct post* p=b->deposito[b->first_out];
    b->first_out=(b->first_out + 1) % MAX;
    b->lenght--;
    return p;
}

void init_queue(struct bacheca* b){
    b->deposito=(struct post**)malloc(MAX*sizeof(struct post*));
    b->first_in=0;
    b->first_out=0;
    b->lenght=0;
}

void load_user_from_file(struct bacheca* b, char nomefile[]){
    FILE* file=fopen(nomefile, "r");
    struct post p;
    init_queue(b);
    while (!feof(file))
    {
        fgets(p.msg, sizeof(p.msg), file);
        fscanf(file, "%d\n", &p.like);
        append(b, p);
    }
    fclose(file);
    
}

void print(struct post* p){
    printf("------------\n");
    printf("%s\n", p->msg);
    printf("%d\n", p->like);
    printf("------------\n");
}

void load_post_condiviso(struct post*p, char nomefile[]){
    FILE* file=fopen(nomefile, "w");
    if (file==NULL)
    {
        perror("errore durante scrittura file");
    }

    
    fprintf(file, "%s\n%d", p->msg, p->like);
    free(p);

    fclose(file);
}

void deallocate(struct bacheca*b){
    for (int i = 0; i < len(b); i++)
    {
        free(b->deposito[i]);
    }
    free(b->deposito);
}