#include <fstream>

using namespace std;

ifstream fin("interclasare3.in");
ofstream fout("interclasare3.out");

int n, m;
int v1[100005], v2[100005];

int main() {
    fin >> n >> m;
    for(int i = 1; i <= n; ++i)
        fin >> v1[i];
    for(int j = 1; j <= m; ++j)
        fin >> v2[j];

    int afisate = 0;
    int i = 1, j = m;
    while(i <= n || j >= 1) {
        while(i <= n && v1[i] % 2 != 0)
            ++i;
        while(j >= 1 && v2[j] % 2 != 0)
            --j;

        if(i > n) {
            fout << v2[j] << ' ';
            --j;

            ++afisate;
            if(afisate % 20 == 0)
                fout << '\n';
        }
        else
            if(j < 1) {
                fout << v1[i] << ' ';
                ++i;

                ++afisate;
                if(afisate % 20 == 0)
                    fout << '\n';
            }
            else
                if(v1[i] <= v2[j]) {
                    fout << v1[i] << ' ';
                    ++i;

                    ++afisate;
                    if(afisate % 20 == 0)
                        fout << '\n';
                }
                else {
                    fout << v2[j] << ' ';
                    --j;

                    ++afisate;
                    if(afisate % 20 == 0)
                        fout << '\n';
                }
                
                
    }
    return 0;
}