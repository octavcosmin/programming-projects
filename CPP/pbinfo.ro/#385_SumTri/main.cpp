#include <cstdio>
#include <algorithm>

using namespace std;

const int NMAX = 100 +5;
int n, result;
int tri[NMAX][NMAX], smax[NMAX][NMAX];

int sum_max(int i, int j);

int main() {
    freopen("sumtri.in", "r", stdin);
    freopen("sumtri.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            scanf("%d", &tri[i][j]);

            if(i == n)
                result = max(result, sum_max(i, j));
        }
    }

    printf("%d", result);
    return 0;
}

int sum_max(int i, int j) {
    if(smax[i][j])
        return smax[i][j];

    if(i ==1 && j == 1)
        smax[i][j] = tri[i][j];
    else {
        if(j == i) {
            smax[i][j] = tri[i][j] + sum_max(i-1, j-1);
            goto skip;
        }
        if(j == 1) {
            smax[i][j] = tri[i][j] + sum_max(i-1, j);
            goto skip;
        }
        smax[i][j] = tri[i][j] + max(sum_max(i-1, j), sum_max(i-1, j-1));
    }
    skip:
    return smax[i][j];
}