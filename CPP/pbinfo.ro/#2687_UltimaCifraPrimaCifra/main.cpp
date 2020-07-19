#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;

    string x, prevx;
    cin >> x;
    for(int i = 2; i <= n; ++i) {
        prevx = x;
        cin >> x;
        if(prevx[prevx.length()-1] == x[0])
            cout << prevx << ' ' << x << '\n';
    }
    return 0;
}
