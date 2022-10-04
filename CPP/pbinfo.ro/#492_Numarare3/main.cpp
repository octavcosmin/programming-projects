#include <bits/stdc++.h>

using namespace std;

int cmmdc(int a, int b) {
    if(!b) return a;
    return cmmdc(b, a%b);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    int res{};
    for(int i = 0; i < n/2; ++i)
        res += (cmmdc(arr[i], arr[n-1 - i]) == 1);

    cout << res;
    return 0;
}