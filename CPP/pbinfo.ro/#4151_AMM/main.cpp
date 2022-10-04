#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int vmin = 100001, vmax{}, pmin, pmax;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        if(a[i] > vmax)
            vmax = a[i], pmax = i;
        if(a[i] < vmin)
            vmin = a[i], pmin = i;
    }
    
    for(vector<int>::iterator it = a.begin() + min(pmin, pmax); it != a.begin() + max(pmin, pmax) + 1; ++it)
        cout << *it << ' ';
    return 0;
}