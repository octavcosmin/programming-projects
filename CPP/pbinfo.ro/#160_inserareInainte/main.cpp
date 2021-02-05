#include <cstdio>
#include <cmath>

using namespace std;

int n;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);

        if((double)sqrt(x) - floor((double)sqrt(x)) == 0) {
            printf("%d %d ", (int)sqrt(x), x);
        }
        else
            printf("%d ", x);
    }
    return 0;
}