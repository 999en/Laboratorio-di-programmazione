#define MAX 4
struct foto{
  char path[256];
  char didascalia[256];
  int like;
};

struct bacheca{
  struct foto** stack;
  int length;
};
