#include <bits/stdc++.h>
#define NMAX 100005
using namespace std;

ifstream fin("mostenire.in");
ofstream fout("mostenire.out");

int n, k;
int saci[NMAX];

int main()
{
    fin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        fin >> saci[i];
    }
    return 0;
}
