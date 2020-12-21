#include <iostream>
#include <cstdio>

#define MOD 1000000007

using namespace std;

int n, x, y, a, nr0, neg, sol;

int main() {

    freopen("crescator.in", "r", stdin);
    freopen("crescator.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        nr0 = 0, neg = 0;
        cin >> x;
        do {
            cin >> a;
            if(a == 0)
                ++nr0;
            if(a < 0)
                neg = a;
            if(a > 0)
                y = a;
        }while(a <= 0);
        // Cazul 1: x 0 y
        if(nr0 == 1 && neg == 0)
            sol = (sol*(y-(x-1))) % MOD;
        else {
            // Cazul 2: x 0 ... 0 y SAU x 0 - ... y cu |-| nu apartine [x,y]
            if(nr0 > 1 && (neg == 0 || 0-neg <= x || 0-neg >= y))
                sol = (sol*( (y-x)*( y-(x-1) - (y-x+1)/2 ) )) % MOD;
            else {
                //Cazul 3
                sol = (sol*( (y-x)*( y-(x-1) - (y-x-1)/2 ) )) % MOD;
            }
        }
    }

    cout << sol;

    return 0;
}