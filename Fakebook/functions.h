#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_queue(struct bacheca*);
int len(struct bacheca*);
int is_empty(struct bacheca*);
int append(struct bacheca*, struct post);
struct post* pop(struct bacheca*);
void deallocate(struct bacheca*);
void read_from_file(struct bacheca*, char*);
void write_on_file(struct bacheca*, char*);
void print(struct post*);


