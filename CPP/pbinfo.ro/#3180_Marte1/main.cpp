#include <stdio.h>

using namespace std;

int main()
{
    int a, b, c, n, m, p;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &n, &m, &p);
    printf("%d", a*n + b*m + c*p);
    return 0;
}
