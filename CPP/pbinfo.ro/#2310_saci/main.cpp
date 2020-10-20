#include <fstream>
using namespace std;

ifstream fin ("saci.in");
ofstream fout ("saci.out");

int n, x, nr_saci, cifra = 10, previous;

int main() {
    fin >> n;
    for(int i = 1; i <= n; ++i) {
        fin >> x;

        bool ok = 1;
        cifra = 10;
        while(x) {
            previous = cifra;
            cifra = x%10;
            if(cifra >= previous)
                ok = 0;
            x /= 10;
        }
        if(ok == 1)
            ++nr_saci;
    }
    fout << nr_saci;
    return 0;
}