#include <bits/stdc++.h>

using namespace std;

FILE *in;
FILE *out;

int a, b;
int valoare, nrDivMax, nrDivCurent, contor;
//int sirPrime[10005];

///Declarare functii
//void construireSirPrime(int l, int r);
int nrDivizori(int x);

int main() {
    in = fopen("maxd.in", "r");
    fscanf(in,"%d%d", &a, &b);
    fclose(in);

    //construireSirPrime(a, b);

    for(int i = a; i <= b; ++i) {
        nrDivCurent = nrDivizori(i);
        if(nrDivCurent > nrDivMax) {
            nrDivMax = nrDivCurent;
            valoare = i;
            contor = 1;
            continue;
        }
        if(nrDivCurent == nrDivMax)
            ++contor;
    }

    out = fopen("maxd.out", "w");
    fprintf(out,"%d %d %d", valoare, nrDivMax, contor);
    return 0;
}

///Functii
int nrDivizori(int x)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
            if (x / i == i)
                cnt++;
            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

/*void construireSirPrime(int st, int dr) {
    int poz = 1;

    ///Caz particular daca intervalul incepe inainte de 2
    if(st <= 2)
        sirPrime[1] = 2, st = 3, ++poz, sirPrime[0]++;

    ///Verificare primalitate
    for(int i = st; i <= dr; i += 2 ) {

        ///Daca i nu e divizibil cu 2
        int d = 3;
        bool prim = 1;
        while(d < i) {
            if(i % d == 0) {
                prim = 0;
                break;
            }
            d += 2;
        }
        ///Adaugare in sir
        if(prim)
            sirPrime[poz++] = i, sirPrime[0]++;
    }
}
*/
