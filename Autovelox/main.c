#include "functions.h"

int main(){
    struct report start;
    load_veichle_from_file(&start, "autovelox.txt");
    struct autovelox* current_node;
    int scelta=-1;
    int i=0;

   while (scelta!=0)
   {
    printf("0 - esci\n 1 - stampa prossima auto\n 2 - stampa chi avrà la multa\n");
    scanf("%d", &scelta);
    switch (scelta)
    {
    case 0:
        return 0;
        break;
    
    case 1:
        current_node=pop(&start);
        print(current_node);
        break;
    
    case 2:
        write_on_file(&start, "multe.txt");
        break;
       
    }
    

   }
   



    

}