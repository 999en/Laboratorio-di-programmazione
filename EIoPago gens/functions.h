#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init_queue(struct contribuenti*);
int append(struct contribuenti*, struct contribuente);
int len(struct contribuenti*);
int is_empty(struct contribuenti*);
struct contribuente* pop(struct contribuenti*);
void load_user_from_file(struct contribuenti*, char[]);
void search(struct contribuenti*, struct contribuenti*);
void load_sospetti(struct contribuenti*, char[]);