#include <fstream>

using namespace std;

ifstream fin("sume.in");
ofstream fout("sume.out");

int n, v[105];

int main() {
    fin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        fin >> x;
        v[i] = v[i-1] + x;
    }

    for(int i = n; i >= 1; --i)
        fout << v[i] << '\n';
    return 0;
}