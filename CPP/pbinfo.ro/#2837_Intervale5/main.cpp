#include <fstream>
using namespace std;

ifstream fin("intervale5.in");
ofstream fout("intervale5.out");

bool vc[101], pereche;

int main() {
    int a;
    while(fin >> a)
        vc[a] = 1;
    int i = 0;
    while(vc[i] == 0)
        ++i;
    for(; i <= 100; ++i) {
        if(vc[i] == 0) {
            int x = i-1;
            while(vc[i] == 0 && i < 100)
                ++i;
            if(vc[i] == 1) {
                fout << x << ' ' << i << '\n';
                pereche = 1;
            }
        }
    }

    if(pereche == 0)
        fout << "nu exista";
    return 0;
}