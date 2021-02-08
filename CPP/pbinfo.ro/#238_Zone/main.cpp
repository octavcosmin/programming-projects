#include <fstream>

using namespace std;

ifstream fin("zone.in");
ofstream fout("zone.out");

int n, v[305], pozpar, pozimpar;

int main() {
    fin >> n; 
    for(int i = 1; i <= 3*n; ++i) {
        fin >> v[i];

        if(i <= n && v[i]%2 == 0 && pozpar == 0)
            pozpar = i;

        if(i > 2*n && v[i]%2 == 1)
            pozimpar = i;
    }
    if(pozpar && pozimpar)
        swap(v[pozpar], v[pozimpar]);

    for(int i = 1; i <= 3*n; ++i)
        fout << v[i] << ' ';
    return 0;
}