#include <cstdio>

using namespace std;

int n, last, aparitii;

int main() {
    FILE *in = fopen("nraparitii.in", "r");
    fscanf(in, "%d", &n);
    for(int i = 0; i < n; ++i)
        fscanf(in, "%d", &last);

    fclose(in);

    in = fopen("nraparitii.in", "r");
    fscanf(in, "%d", &n);
    for(int i = 0; i < n; ++i) {
        int x;
        fscanf(in, "%d", &x);

        if(x == last)
            ++aparitii;
    }
    fclose(in);

    FILE *out = fopen("nraparitii.out", "w");
    fprintf(out, "%d", aparitii);
    fclose(out);
    return 0;
}