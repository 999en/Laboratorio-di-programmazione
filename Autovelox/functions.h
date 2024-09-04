#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_stack(struct autovelox*);
int len(struct autovelox*);
int is_empty(struct autovelox*);
int push(struct autovelox*, struct veicolo);
struct veicolo* pop(struct autovelox*);
void deallocate(struct autovelox*);
void print(struct veicolo*);
void read_from_file(struct autovelox*, char*);
int is_crime(struct veicolo*);
void write_on_file(struct autovelox*, char*);
