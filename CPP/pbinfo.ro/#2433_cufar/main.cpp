#include <bits/stdc++.h>

using namespace std;

ifstream in("cufar.in");
ofstream out("cufar.out");

int ciur[1000005], numar[1000005], rez[1000005], k[1000005];
int p, n, x;

void formare_ciur() {
    for(int i = 2; i <= 1000001; ++i) {
        if(ciur[i] == 0)
            for(int j = i; j <= 1000001; j+=i) {
                ciur[j]++;
                if(k[j] == ciur[j])
                    rez[j] = i;
            }
    }
}

int main()
{
    in >> p >> n;
    for(int i = 1; i <= n; ++i) {
        in >> numar[i];
        in >> k[numar[i]];
    }
    formare_ciur();

    long long suma = 0;
    for(int i = 1; i <= n; ++i)
        suma += rez[numar[i]];
    out << suma;
    return 0;
}
