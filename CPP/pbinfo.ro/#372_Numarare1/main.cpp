#include <iostream>

using namespace std;

int n, paritate1 = -1, paritate2, perechi;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        int cx = x, sumx = 0;
        while(cx) {
            sumx += cx%10;
            cx /= 10;
        }
        paritate2 = sumx % 2;
        if(paritate1 != -1 && paritate1 != paritate2)
            ++perechi;
        paritate1 = paritate2;
    }
    cout << perechi;
    return 0;
}
