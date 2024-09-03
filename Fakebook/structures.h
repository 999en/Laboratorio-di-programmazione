#define MAX 4
struct post{
  char msg[256];
  int like;
};

struct bacheca{
  struct post** queue;
  int length;
  int first_in;
  int first_out;
};
