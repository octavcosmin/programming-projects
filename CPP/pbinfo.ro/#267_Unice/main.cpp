#include <cstdio>

using namespace std;

int N, frec[100];

int main() {
    freopen("unice.in", "r", stdin);
    freopen("unice.out", "w", stdout);

    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++frec[tmp];
    }

    for(int i = 0; i < 100; ++i)
        if(frec[i] == 1)
            printf("%d ", i);
    return 0;
}