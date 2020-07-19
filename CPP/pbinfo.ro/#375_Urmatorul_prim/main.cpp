#include <iostream>

using namespace std;

int n, prim;

int main()
{
    cin >> n;
    if(n < 2)
        cout << 2;
    else {
        do{
            n++;
            prim = 1;
            if(n%2 == 0)
                prim = 0;
            for(int d = 3; d*d <= n && prim == 1; d += 2) {
                if(n%d == 0)
                    prim = 0;
            }
        }while(prim == 0);
        cout << n;
    }
    return 0;
}
