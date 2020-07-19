#include <iostream>

using namespace std;

int n, x, cx, rez, cmin = 10;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        cx = x;
        while(cx > 9)
            cx /= 10;
        if(cx < cmin) {
            cmin = cx;
            rez = x;
        }
        else
             if(cx == cmin && x > rez)
                rez = x;
    }
    cout << rez;
    return 0;
}
