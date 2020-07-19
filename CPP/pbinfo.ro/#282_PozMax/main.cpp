#include <bits/stdc++.h>

using namespace std;

ifstream fin("pozmax.in");
ofstream fout("pozmax.out");

int p1, p2;
double n, nrMax;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i) {
        double x;
        fin >> x;
        if(x == nrMax)
            p2 = i;
        if(x > nrMax) {
            nrMax = x;
            p1 = p2 = i;
        }
    }
    fout << p1 << ' ' << p2;
    return 0;
}
