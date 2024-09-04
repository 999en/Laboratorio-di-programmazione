#include "functions.h"
/*--------------------------------------------------------------------*/

void init_stack(struct autovelox* a){
  a->stack=(struct veicolo**)malloc(MAX*sizeof(struct veicolo));
  a->length=0;
}

/*--------------------------------------------------------------------*/
int len(struct autovelox* a){
  return a->length;
}

/*--------------------------------------------------------------------*/

int is_empty(struct autovelox* a){
  return len(a)==0;
}

/*--------------------------------------------------------------------*/

int push(struct autovelox* a, struct veicolo v){
  if(len(a)>=MAX){
    return 1;
  }
  a->stack=realloc(a->stack, (a->length + 1)*sizeof(struct veicolo*));
  a->stack[a->length]=(struct veicolo*)malloc(sizeof(struct veicolo));
  *(a->stack[a->length])=v;
  a->length++;
  return 0;
}

/*--------------------------------------------------------------------*/

struct veicolo* pop(struct autovelox* a){
  if(is_empty(a)){
    return NULL;
  }
  struct veicolo* v=a->stack[a->length - 1];
  a->length--;
  return v;
}

/*--------------------------------------------------------------------*/

void deallocate(struct autovelox* a){
  while(!is_empty(a)){
    struct veicolo* v=pop(a);
    free(v);
  }
  free(a->stack);
}

/*--------------------------------------------------------------------*/

void print(struct veicolo* v){
  printf("%s ", v->targa);
  printf("%.1f ", v->velocità);
  printf("%.1f\n", v->limite);
}

/*--------------------------------------------------------------------*/

void read_from_file(struct autovelox* a, char* filename){
  FILE* file=fopen(filename, "r");
  if(file==NULL){
    perror("errore durante apertura file\n");
  }
  struct veicolo v;
  while(!feof(file)){
    fscanf(file, "%s ",v.targa);
    fscanf(file, "%f ", &v.velocità);
    fscanf(file, "%f\n", &v.limite);
   push(a,v); 
  }
  fclose(file);
}

/*--------------------------------------------------------------------*/

int is_crime(struct veicolo* v){
  float limite_tollerato=v->limite + (v->limite/100) * 5;
  if(v->velocità>limite_tollerato){
    return 1;
  }
  else return 0;
}

/*--------------------------------------------------------------------*/

void write_on_file(struct autovelox* a, char* filename){
  FILE* file=fopen(filename, "w");
  if(file==NULL){
    perror("errore durante apertura file\n");
  }

  while(!is_empty(a)){
    struct veicolo*v=pop(a);
    if(is_crime(v)==1){
      float limite_superato=v->velocità - v->limite;
      float sanzione=0;
      if(limite_superato<=10.0){
        sanzione=173.0;
      }
      else if(limite_superato>10.0&&limite_superato<40.0){
        sanzione=695.0;
      }
      else if(limite_superato>40.0&&limite_superato<60.0){
        sanzione=2170.0;
      }
      else if(limite_superato>60.0){
        sanzione=3382.0;
      }
      fprintf(file, "%s ", v->targa);
      fprintf(file, "%.1f ", limite_superato);
      fprintf(file, "%.1f\n", sanzione);
    }
  }
  fclose(file);
}
