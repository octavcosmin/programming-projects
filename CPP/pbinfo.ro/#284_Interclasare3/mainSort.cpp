#include <fstream>
#include <algorithm>

using namespace std;
ifstream fin("interclasare3.in");
ofstream fout("interclasare3.out");

int n, m, v[200005];

int main() {
    fin >> n >> m;
    n += m;
    for(int i = 1; i <= n;) {
        int tmp;
        fin >> tmp;
        if(tmp % 2 == 0) {
            v[i] = tmp;
            ++i;
        }
        else
            --n;
    }
    sort(v+1, v+1+n);

    for(int i = 1; i <= n; ++i) {
        fout << v[i] << ' ';
        if(i % 20 == 0)
            fout << '\n';
    }
    return 0;
}