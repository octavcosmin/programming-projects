#include <iostream>
using namespace std;
int n, m, mat[51][51];
struct poz {
    int lin, col, val;
};
poz minfirst = (poz){.lin = 0, .col = 0, .val = 10001}, minlast = (poz){.lin = 0, .col = 0, .val = 10001};
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
            if(mat[i][j] < minfirst.val && j == 1)
                minfirst = (poz){.lin = i, .col = j, .val = mat[i][j]};
            if(mat[i][j] < minlast.val && j == m)
                minlast = (poz){.lin = i, .col = j, .val = mat[i][j]};
        }
    mat[minfirst.lin][minfirst.col] = minlast.val;
    mat[minlast.lin][minlast.col] = minfirst.val;

    for(int i = 1; i <= n; ++i, cout << '\n')
        for(int j = 1; j <= m; ++j)
            cout << mat[i][j] << ' ';
    return 0;
}