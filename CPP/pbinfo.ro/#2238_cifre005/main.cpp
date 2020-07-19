#include <bits/stdc++.h>

using namespace std;

int n, r, nrDiv;

int main()
{
    cin >> n >> r;
    for(int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        if(x%9 == r)
            ++nrDiv;
    }
    cout << nrDiv;
    return 0;
}
