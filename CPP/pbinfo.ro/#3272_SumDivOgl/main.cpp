#include <bits/stdc++.h>

using namespace std;

int n, sdiv;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;

        int cx = x, ogl = 0;
        while(cx) {
            ogl = ogl*10 + cx%10;
            cx /= 10;
        }

        for(int d = 2; d <= ogl/2; ++d)
            if(ogl%d == 0)
                sdiv += d;
        sdiv += ogl+1;
    }
    cout << sdiv;
    return 0;
}
