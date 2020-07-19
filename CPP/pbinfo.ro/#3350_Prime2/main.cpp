#include <iostream>

using namespace std;

int n, nrprime, d;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        bool ok = 1;
        if(x <= 1)
            ok = 0;
        if(x%2 == 0 && x != 2)
            ok = 0;
        for(d = 3; d*d < x && ok; ++d)
            if(x%d == 0)
                ok = 0;
        if(d*d == x)
            ok = 0;
        if(ok == 1)
            ++nrprime;
    }
    cout << nrprime;
    return 0;
}
