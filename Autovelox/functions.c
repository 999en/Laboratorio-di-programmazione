#include "functions.h"

int push(struct report* r, struct autovelox* a){
    if (len(r)>=max)
    {
        printf("coda piena");
        return 1;
    }
    
    r->lenght++;
    r->deposito=realloc(r->deposito, (r->lenght)*sizeof(struct autovelox*));
    r->deposito[(r->lenght)-1]=a;
    return 0;
}

void init_queue(struct report* r){
    r->deposito=NULL;
    r->lenght=0;
}
int len(struct report* r){
    return r->lenght;
}
int is_empty(struct report* r){
    if (len(r)==0)
    {
        printf("coda vuota\n");
        return 1;
    } else return 0;
    
}

struct autovelox* pop(struct report* r){
    if(is_empty(r)==1){
		return NULL;
    }
	

    struct autovelox* a=r->deposito[(r->lenght)-1];
    r->deposito=realloc(r->deposito, ((r->lenght)-1)*sizeof(struct autovelox*));
    r->lenght--;
    return a;
}
void load_veichle_from_file(struct report* r, char nomefile[]){
    FILE* file=fopen(nomefile, "r");
    if (file==NULL)
    {
        printf("qualcosa è andato storto\n");
    }
    //inizializzo pila
    init_queue(r);
    while (!feof(file))
    {
        struct autovelox* a=malloc(sizeof(struct autovelox));
        fscanf(file, "%s %f %f", a->targa, &a->velocità, &a->limite);
        push(r,a);
    }
    fclose(file);
}

void print(struct autovelox* a){
    if (a==NULL)
    {
        return NULL;
    }
    
    printf("----------------\n");
    printf("%s %.1f %.1f\n",  a->targa, a->velocità, a->limite);
    printf("----------------\n");
}

int is_crime(struct autovelox* r){
    float tolleranza= r->limite + 5*(r->limite/100);

    
    if (r->velocità > tolleranza)
    {
        return 1;
    } else return 0;
    

}

void write_on_file(struct report* r, char nomefile[]){
    FILE* file=fopen(nomefile, "w");
    struct autovelox *p=pop(r);
    int l= r->lenght;
    float sanzione=0;
    float limite_superato=0;
    if (file==NULL)
    {
        printf("è andato qualcosa storto durante la scrittura\n");
    }

    for (int i = 0; i < l+1; i++)
    {
        if (is_crime(r->deposito[i])==1)
        {
            limite_superato=(r->deposito[i]->velocità)-(r->deposito[i]->limite);
            if (limite_superato<=10.0)
            {
                sanzione=173.0;
            }
            else if(limite_superato>10.0&&limite_superato<=40.0){
                sanzione=695.0;
            }
            else if(limite_superato>40.0&&limite_superato<=60.0){
                sanzione=2170.0;
            }
            else if(limite_superato>60.0){
                sanzione=3382.0;
            }
            
            fprintf(file, "%s %.1f %.1f\n", r->deposito[i]->targa, limite_superato, sanzione);

        }
        
    }
    
    fclose(file);

}
