#define max 5
struct autovelox{
    char targa[256];
    float velocità;
    float limite;
};

struct report{
    struct autovelox** deposito;
    int lenght;
};
