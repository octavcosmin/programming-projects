#include <fstream>
using namespace std;

ifstream fin("nrprime.xx");
ofstream fout("nrprime.yy");

int n, i, d, x, ePrim, nrPrime;

int main() {
    fin >> n;
    for(i = 0; i < n; ++i) {
        fin >> x;
        ePrim = 1;
        if (x == 0 || x == 1) {
        ePrim = 0;
        }
        else {
            for (d = 2; d <= x / 2; ++d) {
                if (x % d == 0) {
                    ePrim = 0;
                    break;
                }
            }
        }
        if(ePrim) ++nrPrime;
    }
    fout << nrPrime;
    return 0;
}