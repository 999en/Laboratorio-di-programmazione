#include "functions.h"
#include <stdio.h>
int main(){
  struct bacheca b;
  init_stack(&b);
  struct bacheca b2;
  init_stack(&b2);
  read_from_file(&b, "datifoto.txt");
  read_from_file(&b2, "datifoto.txt");
  struct foto* f=pop(&b);
  print(f);
  int scelta=-1;
  while(scelta!=0){
    printf("\n0 - esco\n1 - prossimo post\n2 - aggiungi like\n3 - check\n");
    scanf("%d", &scelta);
    switch(scelta){
      case 0:
        deallocate(&b);
        break;
      case 1:
        f=pop(&b);
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
        int v=is_valid_path(f->path);
        printf("CONTROLLO->%d\n", v);
    }
  }
  stats_on_file(&b2, "stats.txt");
  deallocate(&b2);
  return 0;
}
