#define MAX 15
struct brano{
    char titolo[30];
    char autore[30];
    int durata_in_sec;
    int rips;
};

struct elenco{
    struct brano** deposito;
    int length;

};