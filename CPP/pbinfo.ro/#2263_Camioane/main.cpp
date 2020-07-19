#include <stdio.h>

using namespace std;

int main()
{
    int t1, t2, n, m, z;
    scanf("%d%d%d%d%d", &t1, &t2, &n, &m, &z);
    printf("%d", (t1*n + t2*m)*z);
    return 0;
}
