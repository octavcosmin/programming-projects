#include <cstdio>
#include <vector>

using namespace std;

int n, m, t, k;
vector<bool> lin_ocup, col_ocup;

int main() {
    freopen("potter.in", "r", stdin);
    freopen("potter.out", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &t, &k);

    lin_ocup.resize(n+1);
    col_ocup.resize(m+1);
    for(int i = 1; i <= t; ++i) {
        int tmpx, tmpy;
        scanf("%d%d", &tmpx, &tmpy);
        lin_ocup[tmpx] = true;
        col_ocup[tmpy] = true;
    }

    for(int i = 1; i <= n; ++i)
        printf("%d ", lin_ocup[i]);
    for(int i = 1; i <= m; ++i)
        printf("%d ", col_ocup[i]);
    return 0;
}