#include <cstdio>

using namespace std;

long long exp(int b, int e) {
    if(e == 0) return 1;
    if(e % 2 == 1) return (b*exp(b, e-1));
    return exp(b, e/2)*exp(b, e/2);
}

int main() {
    int a,b;
    scanf("%d%d", &a, &b);
    printf("%ld", exp(a,b));
    return 0;
}