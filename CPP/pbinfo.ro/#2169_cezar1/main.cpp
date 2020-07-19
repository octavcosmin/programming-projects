#include <bits/stdc++.h>

using namespace std;
const int NMAX = 10005;
FILE *in = fopen("cezar1.in", "r");
FILE *out = fopen("cezar1.out", "w");


int N, K;
int x, y;
vector<int> nodes[NMAX];
int nrn[NMAX];
vector<int> nr_treceri;

int numar_treceri(int node) {
    int sol = 1;
    for(int i = 0; i < nrn[node]; ++i)
        sol += numar_treceri(nodes[node][i]);
    return sol;
}

int main()
{
    fscanf(in, "%d%d", &N, &K);

    while(fscanf(in, "%d%d", &x, &y) > 0) {
        nodes[x].push_back(y), ++nrn[x];
        nodes[y].push_back(x), ++nrn[y];
    }

    for(int i = 1; i <= N; ++i)
        nr_treceri.push_back(numar_treceri(i));

    sort(nr_treceri.begin(), nr_treceri.end());

    int suma = 0;
    for(int i = 0; i < (int)nr_treceri.size()-K; ++i)
        suma += nr_treceri[i];

    fprintf(out, "%d\n", suma);
    return 0;
}

