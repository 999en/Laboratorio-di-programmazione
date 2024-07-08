#include "functions.h"
#include <stdio.h>
int main(){
    struct elenco start;
    init_stack(&start);
    read_on_file(&start, "brani.txt");
    write_on_file(&start, "elenco.txt");
    return 0;
}