#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int k,m,n,v[205];
    cin >> k >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> n;
        if(n-(n/k)*k <= (n/k+1)*k-n)
            v[i] = (n/k)*k;
        else
            v[i] = (n/k+1)*k;
    }
    reverse(v, v+m);
    for(int i = 0; i < m; i++)
        cout << v[i] << ' ';
    return 0;
}
