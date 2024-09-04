#include "functions.h"


void init_stack(struct bacheca* b){
  b->stack=(struct foto**)malloc(MAX * sizeof(struct foto*));
  b->length=0;
}

int len(struct bacheca* b){
  return b->length;
}
int is_empty(struct bacheca* b){
  return len(b)==0;
}
int push(struct bacheca* b, struct foto f){
  if(len(b)>=MAX){
    return 1;
  }
  
  b->stack=realloc(b->stack, (b->length + 1)*sizeof(struct foto*));
  b->stack[b->length]=(struct foto*)malloc(sizeof(struct foto));
  *(b->stack[b->length])=f;
  b->length++;
  return 0;
}

struct foto* pop(struct bacheca* b){
  if(is_empty(b)){
    return NULL;
  }
  struct foto* f = b->stack[b->length - 1];
  b->length--;
  return f;
}
void read_from_file(struct bacheca* b, char* filename){
  FILE* file=fopen(filename, "r");
  if(file==NULL){
    perror("errore durante apertura file\n");
  }
  struct foto f;
  while(!feof(file)){
    fgets(f.path, sizeof(f.path), file);
    fgets(f.didascalia, sizeof(f.didascalia), file);
    fscanf(file, "%d\n", &f.like);
    push(b,f);
    //print(&f);
  }
  fclose(file);
}

int is_valid_path(char path[]){
  if(path[0]=='/'){
    int len=strlen(path);
    len=len-1;
    if(path[len]<'A'||path[len]>'z'){
      return 1;
    }
  }
  else return 0;
}

void deallocate(struct bacheca* b){
  while(!is_empty(b)){
    struct foto* f=pop(b);
    free(f);
  }
  free(b->stack);
}

void print(struct foto* f){
  printf("%s\n", f->path);
  printf("%s\n", f->didascalia);
  printf("%d\n", f->like);
}
