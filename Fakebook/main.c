#include "functions.h"
#include <stdio.h>
int main(){
    struct bacheca start;
    load_user_from_file(&start, "post.txt");
    int scelta=-1;
    struct post* current_post=pop(&start);
    print(current_post);
    while (scelta!=0)
    {
        printf("0 - esci\t1 - stampa\t 2 - metti like\t3 - condividi post");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 0:
            free(current_post);
            deallocate(&start);
            break;
        
        case 1:
        if (current_post!=NULL)
        {
            /* code */
            current_post=pop(&start);
            print(current_post);
        }
            break;

        case 2:
            current_post->like++;
            print(current_post);
            break;
        case 3:

            load_post_condiviso(current_post, "condivisi.txt");
            break;
        }
        
    }
    return 0;
    
}