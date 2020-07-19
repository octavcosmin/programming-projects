#include <bits/stdc++.h>
#define PMAX 100+5
#define SMAX 360+5

using namespace std;
FILE *in = fopen("defrag.in", "r");
FILE *out = fopen("defrag.out", "w");

int cerinta, P, S, C;
int hdd[PMAX][SMAX*2];

void citire() {
    fscanf(in,"%d%d%d%d", &cerinta, &P, &S, &C);
    for(int i = 1; i <= C; ++i) {
        int x, y;
        fscanf(in,"%d%d", &x, &y);
        hdd[x][y] = 1;
        hdd[x][S+y] = 1;
        ++hdd[x][0];
    }
    fclose(in);
}

void cerinta1() {
    int nrpiste = 0;
    for(int i = 1; i <= P; ++i)
        if(hdd[i][0] == 0)
            ++nrpiste;
    fprintf(out,"%d", nrpiste);
    fclose(out);
}

void cerinta2() {
    for(int i = 1; i <= P; ++i) {
        int minim = 2147483647, nrOcupSecv = 0;

        for(int j = 1; j <= hdd[i][0]; ++j)
            if(hdd[i][j] == 0)
                ++nrOcupSecv;
        minim = min(minim, nrOcupSecv);

        for(int j = 2; j <= S; ++j) {
            if(hdd[i][j-1] == 0)
                --nrOcupSecv;
            if(hdd[i][j + hdd[i][0] - 1] == 0)
                ++nrOcupSecv;

            minim = min(minim, nrOcupSecv);
        }
        fprintf(out,"%d ", minim);
    }
    fclose(out);
}

int main()
{
    citire();
    if(cerinta == 2)
        cerinta2();
    else
        cerinta1();
    return 0;
}
