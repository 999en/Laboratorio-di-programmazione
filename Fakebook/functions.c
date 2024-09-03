#include "functions.h"


void init_queue(struct bacheca* b){
  b->queue=(struct post**)malloc(MAX*sizeof(struct post*));
  b->length=0;
  b->first_in=0;
  b->first_out=0;
}

int len(struct bacheca* b){
  return b->length;
}

int is_empty(struct bacheca* b){
  return len(b)==0;
}

int append(struct bacheca* b, struct post p){
  if(len(b)>=MAX){
    return 1;
  }
  b->queue[b->first_in]=(struct post*)malloc(sizeof(struct post));
  *(b->queue[b->first_in])=p;
  b->first_in=(b->first_in + 1) % MAX;
  b->length++;
  return 0;
}

struct post* pop(struct bacheca* b){
  if(is_empty(b)){
    return NULL;
  }
  struct post* p=(b->queue[b->first_out]);
  b->first_out=(b->first_out + 1) % MAX;
  b->length--;
  return p;
}

void deallocate(struct bacheca* b){
  while(!is_empty(b)){
    struct post* p=pop(b);
    free(p);
  }
  free(b->queue);
}
void read_from_file(struct bacheca* b, char* filename){
  FILE* file=fopen(filename, "r");
  if(file==NULL){
    perror("errore durante apertura file\n");
  }
  struct post p;
  while(!feof(file)){
    fgets(p.msg, sizeof(p.msg), file);
    fscanf(file, "%d\n", &p.like);
    append(b, p);
  }
  fclose(file);
}
void write_on_file(struct bacheca* b, char* filename){
  FILE* file=fopen(filename, "w");
  if(file==NULL){
    perror("errore durante apertura file\n");
  }

  while(!is_empty(b)){
    struct post* p=pop(b);
    fprintf(file, "%s\n", p->msg);
    fprintf(file, "%d\n", p->like);
    free(p);
  }
  fclose(file);
}
void print(struct post* p){
  printf("\n-----------\n");
  printf("%s", p->msg);
  printf("%d", p->like);
  printf("\n-----------\n");
}


