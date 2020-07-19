#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    int n, s = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        s+=i*(i+1)*pow(-1,i+1);
    printf("Rezultatul este %d", s);
    return 0;
}
