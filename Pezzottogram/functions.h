#include "structures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int init_queue(struct bacheca*);
int len(struct bacheca*);
int is_empty(struct bacheca*);
void push(struct bacheca*, struct foto*);
struct foto* pop(struct bacheca*);
void load_file_from_user(struct bacheca*, char[]);
void print(struct foto*);
int check_path(char[]);