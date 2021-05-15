#include <fstream>
using namespace std;

ifstream fin("progresie3.in");
ofstream fout("progresie3.out");

bool vc[1001];
int nrelem;

int main() {
    int x;
    while(fin >> x) {
        if(vc[x] == 0)
            ++nrelem;
        vc[x] = 1;
    }

    int i = 0;
    while(vc[i] == 0)
        ++i;
    int elem1 = i++;
    while(vc[i] == 0)
        ++i;
    int elem2 = i;

    i = elem1;
    int pas = elem2 - elem1, nrprog = 1;

    while(i < 1000 && nrprog < nrelem) {
        i += pas;
        if(vc[i] == 0) {
            fout << "NU";
            return 0;
        }
        ++nrprog;
    }

    if(nrprog != nrelem) {
        fout << "NU";
        return 0;
    }

    fout << pas;

    return 0;
}