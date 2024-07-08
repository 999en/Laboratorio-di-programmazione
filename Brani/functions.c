#include "functions.h"

void init_stack(struct elenco* e){
    e->deposito=(struct brano**)malloc(MAX*sizeof(struct brano*));
    e->length=0;

}
int len(struct elenco*e){
    return e->length;
}
int is_empty(struct elenco*e){
    if (len(e)==0)
    {
        return 1;
    } else return 0;
    
}
int push(struct elenco* e, struct brano b){
    e->deposito=realloc(e->deposito,(e->length+1)*sizeof(struct brano*));
    e->deposito[e->length]=(struct brano*)malloc(sizeof(struct brano));
    *e->deposito[e->length]=b;
    e->length++;
    return 0;
}

struct brano* pop(struct elenco* e){
    struct brano* b= e->deposito[(e->length)-1];
    e->length--;
    return b;
}
void read_on_file(struct elenco* e, char nomefile[]){
    FILE* file=fopen(nomefile, "r");
    if (file==NULL)
    {
        perror("errore durante apertura file\n");
    }
    struct brano p;
    char titolo[30];
    char autore[30];
    char minuto[5];

   // while (fscanf(file, "%s\n%s\n%d %d\n", titolo, autore, &minuto, &secondi)==4);
    while(!feof(file))
    {
        /*
        

       fgets(p.titolo, sizeof(p.titolo), file);
       fgets(p.autore, sizeof(p.autore), file);
       fscanf(file,"%s", minuto);
        */


       if (fscanf(file, "%[^\n]\n%[^\n]\n%s\n", p.titolo, p.autore, minuto) != 3) {
            break; // Se non riesce a leggere tre elementi, esci dal ciclo
        }
        int found=0;


        for (int i = 0; i < e->length; i++)
        {
            if (strcmp(e->deposito[i]->titolo, p.titolo)==0 && strcmp(e->deposito[i]->autore, p.autore)==0)
            {
                e->deposito[i]->rips++;
                found=1;
                break;
            }
            
        }
        
        if (found==0)
        {
            p.durata_in_sec=(minuto[0] * 60) + (minuto[2] * 10) + (minuto[3]);
            p.rips=1;
            push(e, p);
        }

        
    }
    

    fclose(file);

}

void write_on_file(struct elenco* e, char nomefile[]){
    FILE* file=fopen(nomefile, "w");
    if (file==NULL)
    {
        perror("errore durante scrittura\n");
    }
    struct brano* p;
    while (is_empty(e)!=1)
    {
        p=pop(e);
        fprintf(file, "%s\n", p->titolo);
        fprintf(file, "%s\n", p->autore);
        fprintf(file, "%d\n", p->durata_in_sec);
        fprintf(file, "%d\n", p->rips);
        //free(p);
    }
    fclose(file);
}