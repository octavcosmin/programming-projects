#include <stdio.h>

int t, n, k;

int main() {

    freopen("multiple.in", "r", stdin);
    freopen("multiple.out", "w", stdout);

    scanf("%d", &t);
    for(int i = 1; i <= t; ++i) {
        scanf("%d%d", &n, &k);

        if(k > n) {
            printf("%d\n", k);
            continue;
        }

        int multiplu{k};
        while(multiplu <= n)
            multiplu += k;
        printf("%d\n", multiplu);
    }
    return 0;
}