#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("blackfriday.in", "r", stdin);
    freopen("blackfriday.out", "w", stdout);

    int n; 
    cin >> n;

    vector<int> price(n);
    for(int i = 0; i < n; ++i)
        cin >> price[i];
    
    double vmax{};
    int x, pmax;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(1 - (double)x/price[i] > vmax)
            vmax = 1 - (double)x/price[i], pmax = i+1;
    }
    cout << pmax;
    return 0;
}