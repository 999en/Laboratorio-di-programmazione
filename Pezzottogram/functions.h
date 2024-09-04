#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_stack(struct bacheca*);
int len(struct bacheca*);
int is_empty(struct bacheca*);
int push(struct bacheca*, struct foto);
struct foto* pop(struct bacheca*);
void print(struct foto*);
void deallocate(struct bacheca*);
void read_from_file(struct bacheca*, char*);
void stats_on_file(struct bacheca*, char*);
int is_valid_path(char*);
