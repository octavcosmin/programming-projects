#include <iostream>
using namespace std;
int n,m,a[101][101];
void permutare(int linie) {
    int aux =a[linie][1];
    for(int j = 1; j < m; ++j)
        a[linie][j] = a[linie][j+1];
    a[linie][m] = aux;
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; permutare(i), i++)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for(int i = 1; i <= n; ++i, cout << '\n')
        for(int j = 1; j <= m; ++j)
            cout << a[i][j] << ' ';
        
}