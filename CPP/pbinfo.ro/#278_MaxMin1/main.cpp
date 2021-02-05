#include <iostream>

using namespace std;

int n, m, arr[101], mmax, nrgreater;

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    cin >> m;
    for(int i = 0; i < m; ++i) {
        int tmp;
        cin >> tmp;
        mmax = max(mmax, tmp);
    }

    for(int i = 0; i < n; ++i)
        nrgreater += (arr[i] > mmax);

    cout << nrgreater;
    return 0;
}