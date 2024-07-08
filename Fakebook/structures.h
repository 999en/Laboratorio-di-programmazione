#define MAX 10 
struct post{
    char msg[256];
    int like;
};

struct bacheca{
    struct post** deposito;
    int first_in;
    int first_out;
    int lenght;
};