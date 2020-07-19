#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n % 2 == 0)
    {
        cout << "NU ESTE NOROCOS";
        return 0;
    }
    for(int i = n - n/2; i <= n + n/2; i++)
        cout << i << ' ';
    return 0;
}
