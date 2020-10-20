#include <iostream>
#include <cmath>
using namespace std;

int x, y, nr_cifre, este_pal, nr_pal;
long long compus, ogl, copie;

int main() {
    while(cin >> x >> y && x && y) {
        este_pal = 0;

    /// Cazul X + Y
        nr_cifre = log10(y) + 1;
        compus = x;
        for(int i = 1; i <= nr_cifre; ++i)
            compus *= 10;
        compus += y;

        copie = compus;
        ogl = 0;
        while(copie) {
            ogl = ogl*10 + copie%10;
            copie /= 10;
        }
        if(ogl == compus)
            este_pal = 1;
    /// Cazul Y + X
        nr_cifre = log10(x) + 1;
        compus = y;
        for(int i = 1; i <= nr_cifre; ++i)
            compus *= 10;
        compus += x;

        copie = compus;
        ogl = 0;
        while(copie) {
            ogl = ogl*10 + copie%10;
            copie /= 10;
        }
        if(ogl == compus)
            este_pal = 1;

        if(este_pal)
            ++nr_pal;
    }
    cout << nr_pal;
    return 0;
}