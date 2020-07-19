#include <bits/stdc++.h>

using namespace std;

int n, x, ultimPar = -1;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        if(x%2 == 0)
            ultimPar = x;
    }
    if(ultimPar == -1)
        cout << "IMPOSIBIL";
    else
        cout << ultimPar;
    return 0;
}
