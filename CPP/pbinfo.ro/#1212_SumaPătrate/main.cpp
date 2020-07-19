#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    unsigned long long s;
    for(int i = 1; i <= n; i++)
        s += i*i;
    cout << s%10234573;
    return 0;
}
