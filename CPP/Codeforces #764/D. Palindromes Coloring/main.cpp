#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int fr[26];

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t) {
        int n, k;
        cin >> n >> k;

        string x;
        cin >> x;

        for(int i = 0; i < n; ++i)
            ++fr[x[i] - 'a'];

        sort(fr, fr+25);
        int i{-1};
        while(!fr[++i]);
        
        if(26-i == k) {
            cout << fr[i] << '\n';
            continue;
        }
        if(k == 1) {
            cout << n << '\n';
            continue;
        }

        int sum_even{0};
        for(auto it = fr; it != fr+25; --it)
            if(*it % 2 == 0) sum_even += *it;
        sum_even /= 2;
        if(sum_even % 2) --sum_even;

        int j = -1;
        while(fr[++i] % 2 == 0);

        cout << sum_even + fr[j] << '\n';
    }
    return 0;
}