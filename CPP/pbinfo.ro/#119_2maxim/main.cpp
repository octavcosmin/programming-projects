#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> sir;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sir.push_back(x);
    }
    sort(sir.begin(), sir.end());
    cout << sir[n-1] << ' ' << sir[n-2];
    return 0;
}
