#define MAX 10
struct contribuente{
    char cf[17];
    int *introiti;
    int n_introiti;
};

struct contribuenti{
    struct contribuente** deposito;
    int length;
    int first_in;
    int first_out;
};

