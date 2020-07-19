#include <bits/stdc++.h>

using namespace std;

int n, x, imp1, imp2;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        if(x%2 != 0) {
            imp1 = imp2;
            imp2 = x;
        }
    }

    if(imp1 == 0)
        cout << "Numere insuficiente";
    else
        cout << imp1 << ' ' << imp2;
    return 0;
}
