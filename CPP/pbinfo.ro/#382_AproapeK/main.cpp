#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    if(n-(n/k)*k <= (n/k+1)*k-n)
        cout << (n/k)*k;
    else
        cout << (n/k+1)*k;
    return 0;
}
