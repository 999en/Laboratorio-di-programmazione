#include "functions.h"


void init_queue(struct contribuenti* c){
    c->deposito=(struct contribuente**)malloc(MAX*sizeof(struct contribuente*));
    c->length=0;
    c->first_in=0;
    c->first_out=0;
}

int append(struct contribuenti* c, struct contribuente co){
    if (len(c)>=MAX)
    {
        return 1;
    }
    
    c->deposito[c->first_in]=malloc(sizeof(struct contribuente*));
    *c->deposito[c->first_in]=co;
    c->first_in=(c->first_in+1)%MAX;
    c->length++;
    return 0;
}

int len(struct contribuenti*c){
    return c->length;
}

int is_empty(struct contribuenti* c){
    if (len(c)==0)
    {
        return 1;
    } else return 0;
}

struct contribuente* pop(struct contribuenti*c){
    struct contribuente *co=c->deposito[c->first_out];
    c->first_out=(c->first_out+1)%MAX;
    c->length--;
    return co;
}

void load_user_from_file(struct contribuenti* c, char nomefile[]){
    FILE* file=fopen(nomefile, "r");
    if (file==NULL)
    {
        perror("errore durante apertura file");
    }
    int introito;
    char cf[17];
    while (fscanf(file, "%16s%d", cf, &introito)==2)
    {
        int found=0;
        struct contribuenti temp;
        init_queue(&temp);

        while (is_empty(c)!=1)
        {
            struct contribuente *co=pop(c);
            if (strcmp(co->cf, cf)==0)
            {
                co->introiti=realloc(co->introiti, (co->n_introiti+1)*sizeof(int));
                co->introiti[co->n_introiti]=introito;
                co->n_introiti++;
                found=1;
            }
            append(&temp, *co);
            free(co);
        }
        
        if (found==0)
        {
            struct contribuente new_co;
            strcpy(new_co.cf, cf);
            new_co.introiti=(int*)malloc(sizeof(int));
            new_co.introiti[0]=introito;
            new_co.n_introiti=1;
            append(&temp, new_co);
        }
        
        while (is_empty(&temp)!=1)
        {
            struct contribuente*p=pop(&temp);
            append(c, *p);
            free(p);
        }
        
        free(temp.deposito);
    }
    fclose(file);
    
}

void search(struct contribuenti* c, struct contribuenti* s){
    int somma=0;
    while (is_empty(c)!=1)
    {
        somma=0;
        struct contribuente*p=pop(c);
        for (int i = 0; i < p->n_introiti; i++)
        {
            somma+=p->introiti[i];
        }
        if (somma>5000)
        {
            append(s, *p);
        }
       
       free(p);
    }
}

void load_sospetti(struct contribuenti* c, char nomefile[]){
    FILE*file=fopen(nomefile, "w");
    if (file==NULL)
    {
        perror("errore durante scrittura");
    }
    int somma=0;
    while (is_empty(c)!=1)
    {
        somma=0;
        struct contribuente *p=pop(c);
        fprintf(file, "%s", p->cf);
        for (int i = 0; i < p->n_introiti; i++)
        {
            fprintf(file, " %d", p->introiti[i]);
            somma+=p->introiti[i];
        }
        fprintf(file, " %d\n", somma);
        free(p);
    }
    fclose(file);
}