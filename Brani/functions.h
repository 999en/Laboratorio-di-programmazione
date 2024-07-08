#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_stack(struct elenco*);
int len(struct elenco*);
int is_empty(struct elenco*);
int push(struct elenco*, struct brano);
struct brano* pop(struct elenco*);
void read_on_file(struct elenco*, char[]);
void write_on_file(struct elenco*, char[]);
