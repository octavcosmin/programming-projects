#include <iostream>
#include <cmath>
using namespace std;

int n, x, y, i, difmax, xmax, ymax;

int main() {
    cin >> n;

    for(i = 1; i <= n; ++i) {
        cin >> x >> y;
        if(abs(x-y) > difmax) {
            difmax = abs(x-y);
            xmax = x;
            ymax = y;
        }
    }

    cout << xmax << ' ' << ymax;

    return 0;
}