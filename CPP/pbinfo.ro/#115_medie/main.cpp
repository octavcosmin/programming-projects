#include <bits/stdc++.h>

using namespace std;

int n, nrPar, sumPar, x;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        if(x%2 == 0) {
            nrPar++;
            sumPar += x;
        }
    }
    cout << (double)sumPar/nrPar;
    return 0;
}
