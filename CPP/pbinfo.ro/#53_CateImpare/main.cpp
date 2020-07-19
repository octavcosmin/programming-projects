#include <bits/stdc++.h>

using namespace std;

int x, nrImp;

int main()
{
    do{
        cin >> x;
        if(x%2 != 0)
            nrImp++;
    }while(x);

    cout << nrImp;
    return 0;
}
