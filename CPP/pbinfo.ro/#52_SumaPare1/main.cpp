#include <bits/stdc++.h>

using namespace std;

int x, sum;

int main()
{
    do{
        cin >> x;
        if(x%2 == 0)
            sum += x;
    }while(x);

    cout << sum;
    return 0;
}
