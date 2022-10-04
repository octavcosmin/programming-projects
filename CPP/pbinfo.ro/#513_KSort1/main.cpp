#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> arr(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> arr[i];

    for(int s = 1; s <= k; ++s) {

        vector<int> subsir;
        for(int i = s; i <= n; i += k)
            subsir.push_back(arr[i]);
        int subn = subsir.size();
        
        for(int i = 0; i < subn-1; ++i)
            for(int j = i+1; j <= subn-1; ++j)
                if(subsir[i] > subsir[j]) {
                    int aux = subsir[i];
                    subsir[i] = subsir[j];
                    subsir[j] = aux;
                }
        
        for(int i = 0; i < subn; ++i)
            arr[i*k+s] = subsir[i];
    }

    for(int i = 1; i <= n; ++i)
        cout << arr[i] << ' ';
    return 0;
}