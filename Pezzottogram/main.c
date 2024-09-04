#include "functions.h"
#include <stdio.h>

int main(){
  struct bacheca start;
  init_stack(&start);
  read_from_file(&start, "datifoto.txt");
  struct foto* f= pop(&start);
  print(f);

  
  int scelta=-1;
  while(scelta!=0){
    printf("\n0 - esci\n1 - vedi prossimo post\n2 - aggiungi like\n3 - controllo path\n");
    scanf("%d", &scelta);
    switch(scelta){
      case 0:
        printf("esco");
        break;
      case 1:
        f=pop(&start);
        if(f==NULL){
          return 0;
        }
        print(f);
        break;
      case 2:
        f->like++;
        print(f);
        break;
      case 3:
        
        int v = is_valid_path(f->path);
        printf("CONTROLLO PATH:----------->%d\n", v);
        break;
    
    }
  }
  deallocate(&start);
  return 0;
}
