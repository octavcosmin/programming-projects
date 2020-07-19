#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int a2 = a*a, a4 = a*a*a*a;
    double radical = sqrt(a2+a4);
    cout << (int)((3*(a2+a4))/(a2+a4+radical)+radical);
    return 0;
}
