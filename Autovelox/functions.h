#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void load_veichle_from_file(struct report*, char[]);
int push(struct report*, struct autovelox*);
struct autovelox* pop(struct report*);
void print(struct autovelox*);
void init_queue(struct report *);
int is_crime(struct autovelox*);
void write_on_file(struct report*, char[]);
int is_empty(struct report*);
int len(struct report*);
//void pop(struct report*);
//void print(struct report*, int);