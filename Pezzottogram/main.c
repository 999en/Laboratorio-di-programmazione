#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    struct bacheca bacheca;
	init_queue(&bacheca);
	load_file_from_user(&bacheca,"datifoto.txt");
	struct foto *p=pop(&bacheca);
	int scelta=-1;
	while (scelta!=0)
	{
		printf("0 - esci 1 - stampa prossima foto - 2 aggiungi like - 3 - check path - ->");
		scanf("%d", &scelta);

		switch (scelta)
		{
		case 0:
			printf("chiusura programma\n");
			break;
		
		case 1:
			if (p==NULL)
			{
				break;
			}
		
			print(p);
			p=pop(&bacheca);
			
			
			break;
		case 2:
			p->like++;
			print(p);
			break;

		case 3:
			int a=check_path(p->img_path);
			printf("1 se è un percorso file, 0 il contrario-->");
			printf("[%d]\n\n", a);
			break;
		}


	}
	return 0;


}