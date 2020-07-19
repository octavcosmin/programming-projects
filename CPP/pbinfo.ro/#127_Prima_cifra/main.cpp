#include <bits/stdc++.h>

using namespace std;

int n, sum;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        string x;
        cin >> x;
        sum += x[0]-'0';
    }
    cout << sum;
    return 0;
}
