#include <bits/stdc++.h>

using namespace std;
#define NMAX 1000005

vector<int> divizori(NMAX);
void makeDiv() {
    for(int d = 1; d <= NMAX; ++d)
        for(int i = d; i <= NMAX; i += d)
            ++divizori[i];
}

int n, cerinta, nrDivMax;
map<int, int> nrd;
vector<int> numere;

int main()
{
    makeDiv();
    scanf("%d%d", &n, &cerinta);
    for(int i = 1; i <= n; ++i) {
        int temp;
        scanf("%d", &temp);
        numere.push_back(temp);
        nrd.insert({divizori[temp], i});
        nrDivMax = max(nrDivMax, divizori[temp]);
    }

    pair<int, int> pozmax = {0, 0};
    for(int i = n-1; i >= 0 && nrd[i] == nrDivMax; --i) {

    }
    return 0;
}
