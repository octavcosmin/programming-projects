#include <iostream>
using namespace std;
int n, m, mat[51][51];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> mat[i][j];
    for(int i = 1; i <= n; ++i)
        mat[i][1] = mat[i][m] = mat[n][m];
    for(int j = 2; j < m; ++j)
        mat[1][j] = mat[n][j] = mat[n][m];
    for(int i = 1; i <= n; ++i, cout << '\n')
        for(int j = 1; j <= m; ++j)
            cout << mat[i][j] << ' ';
    return 0;
}