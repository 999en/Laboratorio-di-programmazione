#include "functions.h"
#include <stdio.h>
int main(){
    struct contribuenti start;
    init_queue(&start);
    load_user_from_file(&start, "dipendenti.txt");
    struct contribuenti sospetti;
    init_queue(&sospetti);
    search(&start, &sospetti);
    load_sospetti(&sospetti, "sospetti.txt");
    return 0;
}