#include <iostream>
using namespace std;
int ka, kb, r, a, b, nrate;
int main() {
    cin >> ka >> kb;
    a = 1;
    b = 2;
    for(r = 1; ka > 0 && kb > 0; ++r) {
        switch(r) {
            case 1:
                nrate = 1;
                break;
            case 2:
                nrate = 2;
                break;
            case 3:
                nrate = 3;
                break;
            default:
                a = b;
                b = nrate;
                nrate = a+b;
        }
        ka -= nrate/2 + nrate%2;
        kb -= nrate/2;
    }
    --r;
    if(ka < 0 || kb < 0) {
        ka += nrate/2 + nrate%2;
        kb += nrate/2;
        --r;
    }
    cout << r  << '\n' << ka << '\n' << kb;
    return 0;
}