#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double d1,d2;
    cin >> d1 >> d2;
    cout << 2*(sqrt(d1*d1+d2*d2)) << ' ' << d1*d2/2;
    return 0;
}
