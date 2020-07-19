#include <iostream>

using namespace std;

long long n, x, minim1, minim2, maxim1, maxim2;
///minim1 < minim2 < ... < maxim1 < maxim2

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        if(x <= minim1) {
            minim2 = minim1;
            minim1 = x;
        }
        else
            if(x <= minim2)
                minim2 = x;

        if(x >= maxim2) {
            maxim1 = maxim2;
            maxim2 = x;
        }
        else
            if(x >= maxim1)
                maxim1 = x;
    }

    if(minim1*minim2 > maxim1*maxim2)
        cout << minim1*minim2;
    else
        cout << maxim1*maxim2;
    return 0;
}
