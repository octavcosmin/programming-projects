#include <fstream>
using namespace std;
ifstream fin("comori1.in");
ofstream fout("comori1.out");
int n, a, b;
bool found;
int main() {
    fin >> n >> a;
    for(int i = 2 ; i <= n; ++i) {
        fin >> b;
        if(b < a) {
            found = 1;
            fout << i << ' ';
        }
        a = b;
    }
    if(!found) fout << 0;
    return 0;
}