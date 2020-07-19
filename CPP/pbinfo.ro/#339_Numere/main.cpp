#include <bits/stdc++.h>

using namespace std;

int n, x;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        if(x%2 == 0){
            cout << x;
            return 0;
        }
    }
    cout << "IMPOSIBIL";
    return 0;
}
