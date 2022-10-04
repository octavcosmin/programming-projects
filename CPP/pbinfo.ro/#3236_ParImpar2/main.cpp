#include <fstream>
using namespace std;
ifstream fin("parimpar2.in");
ofstream fout("parimpar2.out");
int i, p, soli, solp, x;
int main() {
    fin >> i >> p;
    while(fin >> x) {
        if(x % 2) --i;
        else --p;
        
        if(!i) soli = x, --i;
        if(!p) solp = x, --p;
    }
    if(i > 0 || p > 0)
        fout << "Nu Exista";
    else
        fout << solp << ' ' << soli;
        return 0;
}