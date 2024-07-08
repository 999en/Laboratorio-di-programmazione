#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append(struct bacheca*, struct post);
int len(struct bacheca*);
int is_empty(struct bacheca*);
struct post* pop(struct bacheca*);
void init_queue(struct bacheca*);
void load_user_from_file(struct bacheca*, char[]);
void print(struct post*);
void load_post_condiviso(struct post*, char[]);
void deallocate(struct bacheca*);