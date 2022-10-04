#include <iostream>
using namespace std;
int n, x, min1, min2, min3;
int main() {
    min1 = min2 = min3 = 10001;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        if(x < min3)
            min1 = min2,
            min2 = min3,
            min3 = x;
        else if(x < min2)
            min1 = min2,
            min2 = x;
            else if(x < min1)
                min1 = x;
    }
    cout << min1 << ' ' << min2 << ' ' << min3;
    return 0;
}