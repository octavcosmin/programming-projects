#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int c1 = n/100, c2 = n/10%10, c3 = n%10;
    if(c1 <= c2 && c2 <= c3)
    {
        cout << c2;
        return 0;
    }
    if(c3 <= c2 && c2 <= c1)
    {
        cout << c2;
        return 0;
    }
    if(c2 <= c1 && c1 <= c3)
    {
        cout << c1;
        return 0;
    }
    if(c3 <= c1 && c1 <= c2)
    {
        cout << c1;
        return 0;
    }
    if(c2 <= c3 && c3 <= c1)
    {
        cout << c3;
        return 0;
    }
    if(c1 <= c3 && c3 <= c2)
    {
        cout << c3;
        return 0;
    }
    return 0;
}
