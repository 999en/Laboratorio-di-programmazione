#define MAX 5
struct veicolo{
  char targa[10];
  float velocità;
  float limite;
};

struct autovelox{
  struct veicolo** stack;
  int length;
};
