#include <bits/stdc++.h>
#define LMAX 256+5
#define CMAX 65536+5

using namespace std;

FILE *in, *out;

int readInt() {
    int x;
    fscanf(in,"%d", &x);
    return x;
}

struct cifre{
    int c0, c1, c2;
} sume_partiale[LMAX][CMAX];
bool operator==(cifre x, cifre y) {
    return (x.c0 == y.c0 && x.c1 == y.c1 && x.c2 == y.c2);
}

vector<cifre> x;
int l, c, nr_omogene;

void bordare_x() {
    x.push_back((cifre){.c0 = 0, .c1 = 0, .c2 = 0});
}

void creare_x(int i1, int i2) {
    for(int m = 1; m <= c; ++m) {
        int nrc0 = sume_partiale[i2][m].c0 - sume_partiale[i1-1][m].c0;
        int nrc1 = sume_partiale[i2][m].c1 - sume_partiale[i1-1][m].c1;
        int nrc2 = sume_partiale[i2][m].c2 - sume_partiale[i1-1][m].c2;
        x.push_back((cifre){.c0 = x[m-1].c0 + nrc0 - nrc1,
                            .c1 = x[m-1].c1 + nrc1 - nrc2,
                            .c2 = x[m-1].c2 + nrc2 - nrc0});
    }
}

bool sortare_aparitii(cifre x, cifre y) {
    if(x.c0 == y.c0) {
        if(x.c1 == y.c1) {
            return x.c2 < y.c2;
        }
        return x.c1 < y.c1;
    }
    return x.c0 < y.c0;
}

int main()
{
    in = fopen("omogene.in","r");
    l = readInt(), c = readInt();
    for(int i = 1; i <= l; ++i) {
        for(int j = 1; j <= c; ++j) {
            int temp = readInt();
            if(temp == 0) {
                sume_partiale[i][j].c0 = sume_partiale[i-1][j].c0 + 1;
                sume_partiale[i][j].c1 = sume_partiale[i-1][j].c1;
                sume_partiale[i][j].c2 = sume_partiale[i-1][j].c2;
            }
            if(temp == 1) {
                sume_partiale[i][j].c0 = sume_partiale[i-1][j].c0;
                sume_partiale[i][j].c1 = sume_partiale[i-1][j].c1 + 1;
                sume_partiale[i][j].c2 = sume_partiale[i-1][j].c2;
            }
            if(temp == 2) {
                sume_partiale[i][j].c0 = sume_partiale[i-1][j].c0;
                sume_partiale[i][j].c1 = sume_partiale[i-1][j].c1;
                sume_partiale[i][j].c2 = sume_partiale[i-1][j].c2 + 1;
            }
        }
    }
    fclose(in);

    for(int i1 = 1; i1 <= l; ++i1) {
        for(int i2 = i1; i2 <= l; ++i2) {
            x.clear();
            bordare_x();

            creare_x(i1, i2);
            sort(x.begin(), x.end(), sortare_aparitii);

            /*for(int k = 0; k <= c; ++k)
                cout << x[k].c0 << ' ';
            cout << '\n';
            for(int k = 0; k <= c; ++k)
                cout << x[k].c1 << ' ';
            cout << '\n';
            for(int k = 0; k <= c; ++k)
                cout << x[k].c2 << ' ';
            cout << "\n\n";*/

            int lsecv = 1;
            for(int i = 1; i <= c; ++i) {
                if(x[i] == x[i-1])
                    ++lsecv;
                else {
                    nr_omogene += lsecv*(lsecv-1)/2;
                    lsecv = 1;
                }
            }
            nr_omogene += lsecv*(lsecv-1)/2;
        }
    }
    out = fopen("omogene.out","w");
    fprintf(out,"%d", nr_omogene);
    fclose(out);
    return 0;
}
