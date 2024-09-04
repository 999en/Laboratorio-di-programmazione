#include "functions.h"

int init_queue(struct bacheca* b){
    b->deposito=NULL;
    b->length=0;
}
int len(struct bacheca*b){
    return b->length;
}
int is_empty(struct bacheca*b){
    if (len(b)==0)
    {
        return 1;
    } else return 0;
    
}
void push(struct bacheca*b, struct foto*f){
    b->length=b->length+1;
    b->deposito=realloc(b->deposito, (b->length)*sizeof(struct foto*));
    b->deposito[(b->length)-1]=f;
}
struct foto* pop(struct bacheca*b){
    if (is_empty(b)==1)
    {
        return NULL;
    }
    
    struct foto* f=b->deposito[(b->length)-1];
    b->deposito=realloc(b->deposito, ((b->length)-1)*sizeof(struct foto*));
    b->length--;
    return f;
}
void load_file_from_user(struct bacheca* b, char nomefile[]){
    FILE* file=fopen(nomefile, "r");
    if (file==NULL)
    {
        perror("errore durante apertura file");
    }

    while (!feof(file))
    {
        struct foto*f=malloc(sizeof(struct foto));
        fgets(f->img_path, sizeof(f->img_path), file);
        fgets(f->didascalia, sizeof(f->didascalia), file);
        fscanf(file, "%d\n", &f->like);
        push(b, f);
       
    }
    fclose(file);
}

void print(struct foto*f){
    printf("\n---------------\n");
    printf("path: %s\n", f->img_path);
    printf("didascalia: %s\n", f->didascalia);
    printf("like: %d\n", f->like);
    printf("---------------\n");
}
int check_path(char path[]){
    if (path[0]=='/')
    {
        int len= strlen(path);
        if (path[(len)-1]<'A'||path[(len)-1]>'z')
        {
            return 1;
        }
        
    }
    else return 0;
    
}