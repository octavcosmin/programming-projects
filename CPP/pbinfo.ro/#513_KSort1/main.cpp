#include <iostream>

using namespace std;

int n, k, v[1005];

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> v[i];

    for(int sir = 1; sir <= k; ++sir) {
        for(int i = sir; i < n; i += k) {
            for(int j = sir; j <= n-1; j += k)
                if(v[j] > v[j+1])
                    swap(v[j], v[j+1]);
        }
    }

    for(int i = 1; i <= n; ++i)
        cout << v[i] << ' ';
    return 0;
}