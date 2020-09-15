#include<stdio.h>
#include<algorithm>

int main() {
    int a, b;

    scanf("%d%d", &a, &b);
    for(int d = std::min(a,b); d >= 1; --d) {
        if(a%d == 0 && b%d == 0)
            printf("%d ", d);
    }
    return 0;
}