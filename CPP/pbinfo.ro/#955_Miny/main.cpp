#include <bits/stdc++.h>

using namespace std;

FILE *in = fopen("miny.in","r");
FILE *out;

int n, v[50005];

int main()
{
    ///Citire
    fscanf(in,"%d", &n);
    int p = 1;
    for(int i = 1; i <= n; ++i) {
        fscanf(in,"%d", &v[i]);
        p *= v[i];
        p %= 100;
    }
    fclose(in);

    ///Cerinta a)
    out = fopen("miny.out","w");
    fprintf(out,"%d\n", p/10);
    fclose(out);
    return 0;
}
