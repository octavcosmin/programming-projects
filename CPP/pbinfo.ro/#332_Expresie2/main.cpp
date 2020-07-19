#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, s = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        s+=i*(i+1);
    printf("Rezultatul este %d", s);
    return 0;
}
