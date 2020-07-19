#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    long long p = 1;
    for(int i = 1; i <= n; i++)
        p *= i;
    printf("%lld", p);
    return 0;
}
