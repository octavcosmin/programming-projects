#include <bits/stdc++.h>
#define NMAX 100005

using namespace std;

FILE *in, *out;

bool i1[NMAX], i2[NMAX], f[NMAX];
int n;

int parcurgere(bool x[]) {
    int operatii = 0;
    for(int i = 1; i < n; ++i) {
        if(x[i] != f[i]) {
            ++operatii;
            x[i] = !x[i];
            x[i+1] = !x[i+1];
            x[i+2] = !x[i+2];
        }
    }
    return operatii;
}

int main()
{
    in = fopen("leduri.in","r");
    fscanf(in,"%d", &n);
    for(int i = 1; i <= n; ++i) {
        int temp;
        fscanf(in,"%d", &temp);
        i1[i] = temp;
        i2[i] = i1[i];
    }
    for(int i = 1; i <= n; ++i) {
        int temp;
        fscanf(in,"%d", &temp);
        f[i] = temp;
    }

    i2[1] = !i2[1];
    i2[2] = !i2[2];
    int rez1 = parcurgere(i1);
    int rez2 = parcurgere(i2) + 1;
    if(i1[n] == f[n] && i2[n] == f[n]) {
        out = fopen("leduri.out","w");
        fprintf(out,"%d", min(rez1, rez2));
        fclose(out);
        return 0;
    }
    if(i1[n] == f[n]){
        out = fopen("leduri.out","w");
        fprintf(out,"%d", rez1);
        fclose(out);
        return 0;
    }
    if(i2[n] == f[n]){
        out = fopen("leduri.out","w");
        fprintf(out,"%d", rez2);
        fclose(out);
        return 0;
    }
    out = fopen("leduri.out","w");
    fprintf(out,"-1");
    fclose(out);
    return 0;
}
