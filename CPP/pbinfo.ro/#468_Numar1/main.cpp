#include <iostream>

using namespace std;

int main()
{
    short int n;
    cin >> n;
    cout << (n/100*10+n%10)*(n/100*10+n%10);
    return 0;
}
