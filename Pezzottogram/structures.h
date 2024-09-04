#define MAX 4
struct foto{
    char img_path[256]; 
    char didascalia[256];
    int like;
};

struct bacheca{
    struct foto** deposito;
    int length;
};