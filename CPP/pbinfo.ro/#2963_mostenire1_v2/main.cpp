#include <bits/stdc++.h>

using namespace std;
FILE *in, *out;

struct mytype {
    int suma, indice, nrsaci, mostenitor;
};
vector<mytype> siruri;

int n, f, sum;
vector<int> saci;

void citire() {
    in = fopen("mostenire.in", "r");
    fscanf(in,"%d%d", &n, &f);
    for(int i = 0; i < n; ++i) {
        int temp;
        fscanf(in,"%d", &temp);
        saci.push_back(temp);
        sum += temp;
    }
    fclose(in);
}

int verificare_suma(int s) {
    int secvsum = 0, nrsecv = 0, nrs = 0;
    vector<mytype> temp_siruri;
    for(int i = 0; i < n; ++i) {
        secvsum += saci[i];
        ++nrs;
        if(secvsum >= s) {
            ++nrsecv;
            temp_siruri.push_back((mytype){.suma = secvsum, .indice = nrsecv, .nrsaci = nrs});
            secvsum = 0;
            nrs = 0;
        }
    }
    if(nrsecv < f)
        return 0;///Suma e prea mare
    if(nrsecv == f) {
        siruri = temp_siruri;
        return 1;///Avem o solutie
    }
    if(nrsecv > f)
        return 1;///Suma e prea mica
}

int cautare_binara(int st, int dr) {
    int mid = (st+dr)/2;
    if(st > dr)
        return 0;
    int temp_rez = verificare_suma(mid);
    if(temp_rez == 0)
        return cautare_binara(st, mid-1);
    if(temp_rez == 1)
        return cautare_binara(mid+1, dr);
}

bool by_value(mytype x, mytype y) {
    return x.suma < y.suma;
}
bool by_order(mytype x, mytype y) {
    return x.indice < y.indice;
}

int main()
{
    citire();
    cautare_binara(1, sum);
    sort(siruri.begin(), siruri.end(), by_value);
    out = fopen("mostenire.out", "w");
    fprintf(out,"%d\n", siruri[0].suma);
    for(int i = 0; i < siruri.size(); ++i)
        siruri[i].mostenitor = f-i;
    sort(siruri.begin(), siruri.end(), by_order);
    for(int i = 0; i < siruri.size(); ++i)
        fprintf(out,"%d %d\n", siruri[i].mostenitor, siruri[i].nrsaci);
    return 0;
}
