#include <bits/stdc++.h>

using namespace std;
///CONSTANTE{
const int NMAX = 5000 +5;
const int XMAX = 30000 +5;
///}

///STRUCTURI{
struct factori_primi{
    int factor, exponent;

    factori_primi& operator/=(const int& a) {
        factor /= a;
        exponent /= a;
        return *this;
    }
    factori_primi& operator/(const int& a) {
        factor /= a;
        exponent /= a;
        return *this;
    }
    factori_primi& operator%(const int& a) {
        factor %= a;
        exponent %= a;
        return *this;
    }
    bool operator==(const int& a) {
        return (factor == a && exponent == a);
    }
    bool operator!=(const int& a) {
        return !(factor == a && exponent == a);
    }
};
///}

///VARIABILE GLOBALE{
int N, M;
vector<int> factori(XMAX);
vector<factori_primi> fact_curent;
///}

///PRE-DECLARARE FUNCTII{
void descompunere_in_factori_primi(int x);
///}

int main()
{
    freopen("exp.in", "r", stdin);
    freopen("exp.out", "w", stdout);

    scanf("%d%d", &M, &N);

    for(int i = 0; i < N; ++i) {
        int x;
        scanf("%d", &x);

        fact_curent.clear();
        descompunere_in_factori_primi(x);

        ///Impartire factori la m;
        for(auto it = fact_curent.begin(); it != fact_curent.end(); ++it) {
            factori[it->factor] += it->exponent;
            //cout << it->factor << ' ' << it->exponent << '\n';
        }
    }

    ///Verificare daca exponentii sunt multipli de M
    for(auto it = factori.begin(); it !=factori.end(); ++it) {
        if(*it % M == 0)
            *it /= M;
        else {
            printf("0\n");
            return 0;
        }
    }

    ///Afisare factori
    printf("1\n");
    for(int i = 0; i < factori.size(); ++i)
        if(factori[i])
            printf("%d %d\n", i, factori[i]);
    return 0;
}

///DECLARARE FUNCTII{
void descompunere_in_factori_primi(int x) {
    int f = 2, e;
    while(x > 1) {
        e = 0;
        while(x%f == 0) {
            ++e;
            x /= f;
        }
        ///Adaugare factor in vector;
        if(e)
            fact_curent.push_back({f, e});

        ///Marire fact cautat cu 2 (sau cu 1 daca este 2);
        if(f == 2)
            ++f;
        else
            f += 2;
    }
}
///}
