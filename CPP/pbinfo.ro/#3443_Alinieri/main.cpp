#include <cstdio>

#define NMAX 181

using namespace std;

FILE *in, *out;
int N, P, Z;
int fr[NMAX], current[NMAX];
long long rez, count;

int main() {
    in = fopen("alinieri.in", "r");
    fscanf(in, "%d%d%d", &N, &P, &Z);

    for(int i = 1; i <= N; ++i) {
        int tmp;
        fscanf(in, "%d", &tmp);
        ++fr[tmp % 180];
    }
    fclose(in);

    for(int i = 1; i <= 180; ++i) {
        for(int j = 0; j < 180; ++j)
            current[j] = 0;
        for(int j = 0; j < 180; ++j)
            current[(j*i)%180] += fr[j];
        int tmp{0};
        for(int j = 0; j < 180; ++j)
            if(current[j] >= P)
                ++tmp;
        count += tmp;

        if(i <= Z % 180)
            rez += tmp;
    }
    rez += count * (Z / 180);

    out = fopen("alinieri.out", "w");
    fprintf(out, "%lld", rez);
    fclose(out);
    return 0;
}