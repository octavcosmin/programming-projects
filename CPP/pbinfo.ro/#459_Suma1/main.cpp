#include <bits/stdc++.h>

using namespace std;

int x, prevX, sum;

int main()
{
    do{
        prevX = x;
        cin >> x;
        sum += x;
    }while(prevX != x);

    cout << sum;
    return 0;
}
