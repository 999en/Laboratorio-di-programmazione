#include "functions.h"
#include <stdio.h>
int main(){
  struct autovelox a;
  init_stack(&a);
  read_from_file(&a, "autovelox.txt");
  write_on_file(&a, "multe.txt");
  deallocate(&a);
}
