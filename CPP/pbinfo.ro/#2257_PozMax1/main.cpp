#include <bits/stdc++.h>

using namespace std;

int p1, p2;
double n, nrMax;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        double x;
        cin >> x;
        if(x == nrMax)
            p2 = i;
        if(x > nrMax) {
            nrMax = x;
            p1 = p2 = i;
        }
    }
    cout << p1 << ' ' << p2;
    return 0;
}
