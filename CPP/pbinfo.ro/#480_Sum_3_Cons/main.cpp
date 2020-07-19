#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n%3 == 0)
        printf("%d %d %d", n/3-1, n/3, n/3+1);
    else
        printf("NU EXISTA");
    return 0;
}
