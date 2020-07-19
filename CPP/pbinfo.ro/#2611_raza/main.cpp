#include <iostream>

using namespace std;

int cmmdc(long long a, long long b);

int main()
{
    long long a,b;
    cin >> a >> b;
    if(a % 2 == 1 && b % 2 == 1)
        cout << a + b - 2;
    else
        cout << (a + b)/cmmdc(a,b) - 2;
    return 0;
}

int cmmdc(long long a, long long b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}
