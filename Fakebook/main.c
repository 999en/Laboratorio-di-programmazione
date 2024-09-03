#include "functions.h"
#include <stdio.h>

int main(){
  struct bacheca start;
  init_queue(&start);
  struct bacheca b2;
  init_queue(&b2);
  read_from_file(&start, "post.txt");
  struct post* current=pop(&start);
  print(current);
  int scelta=-1;
  while(scelta!=0){
    printf("\n0 - esci\n1 - post successivo\n2 - like\n3 - condividi\n");
    scanf("%d", &scelta);
    switch(scelta){
      case 0:
        printf("esco\n");
        deallocate(&start);
        break;
      case 1:
        current=pop(&start);
        if(current==NULL){
          return 0;
          
        }
        print(current);
        break;
      case 2:
        current->like++;
        print(current);
        break;
      case 3:
        append(&b2, *current);
        write_on_file(&b2, "condivisi.txt");
        break;
    }
  
  }
  return 0;
}
