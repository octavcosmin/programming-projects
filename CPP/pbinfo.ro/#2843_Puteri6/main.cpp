#include <fstream>
#include <cmath>

using namespace std;
ifstream fin("puteri6.in");
ofstream fout("puteri6.out");

int fr[10], n;

int main() {
    fin >> n;
    int x, citite{0};
    while(fin >> x)
        ++fr[(int)log10(x)+1], ++citite;

    if(citite < n) {
        fout << "Nu exista";
        return 0;
    }

    fout << 1;
    int nrElem{0};
    for(int i = 0; i < 10, nrElem < n; ++i) {
        nrElem += fr[i];
        if(nrElem < n && i > 0)
            fout << 0;
    }
    
    return 0;
}