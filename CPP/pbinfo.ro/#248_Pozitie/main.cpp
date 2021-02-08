#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("pozitie.in");
ofstream fout("pozitie.out");

int n, v[10005], elem1;

int main() {
    fin >> n;
    for(int i = 1; i <= n; ++i)
        fin >> v[i];
    
    elem1 = v[1];

    sort(v+1, v+1+n);

    for(int i = 1; i <= n; ++i)
        if(v[i] == elem1) {
            fout << i;
            return 0;
        }
    return 0;
}