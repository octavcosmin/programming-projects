#include <bits/stdc++.h>

using namespace std;

int main()
{
    int pairs = 0;
    string x, y;
    do{
        cin >> x >> y;
        if(x[0] == y[0])
            ++pairs;
    }while(x != "0" && y != "0");
    cout << --pairs;
    return 0;
}
