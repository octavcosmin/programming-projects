#include <iostream>
#include <cmath>
using namespace std;
short int x;
int k;
int main() {
    cin >> k;
    for(x = 1; x*x < k; ++x) {
        double sq = sqrt(k-x*x);
        if(sq < x) return 0;
        if((int)sq == sq)
            cout << x << ' ' << sq << '\n';
    }
    return 0;
}