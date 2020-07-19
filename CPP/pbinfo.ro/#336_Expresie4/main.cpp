#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int m = n, x = 1, s = 0;
    for(int i = 1; i <= n; i++)
    {
        s += x*m;
        x++,m--;
    }
    printf("Rezultatul este %d", s);
    return 0;
}
