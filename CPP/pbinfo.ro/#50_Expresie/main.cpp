#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long n;
    scanf("%lld", &n);
    long long s = 0;
    for(int j = 1; j <= n; j++)
    {
        long long p = 1;
        for(int i = 1; i <= j; i++)
            p *= i;
        s += p;
    }
    printf("Rezultatul este %lld", s);
    return 0;
}
