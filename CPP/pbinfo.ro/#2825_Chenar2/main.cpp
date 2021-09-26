#include <iostream>
using namespace std;
int n, m, mat[101][101], fr[101], x;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
            if(i == 1 || i == n || j == 1 || j == m)
                ++fr[mat[i][j]];
        }
    cin >> x;
    if(fr[x])
        cout << "DA";
    else
        cout << "NU";
    return 0;
}