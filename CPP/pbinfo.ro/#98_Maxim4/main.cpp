#include <fstream>

using namespace std;

ifstream fin ("maxim4.in");
ofstream fout ("maxim4.out");

int n, nrmax, aparitii;

int main() {
    fin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        fin >> x;

        if(x == nrmax) {
            ++aparitii;
            continue;
        }
        if(x > nrmax) {
            nrmax = x;
            aparitii = 1;
            continue;
        }
    }

    fout << nrmax << ' ' << aparitii;
    return 0;
}