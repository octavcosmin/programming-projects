#include <fstream>
using namespace std;

ifstream fin("podm.in");
ofstream fout("podm.out");
 
long long bst[501][501], d[501];
int n;
 
int main(void)
{
    fin >> n;
    for(int i = 0; i <= n; ++i)
        fin >> d[i];
 
    for(int i = 1; i <= n; ++i)  bst[i][i] = 0;
    for(int i = 1; i <= n-1; ++i)  bst[i][i + 1] = d[i - 1] * d[i] * d[i + 1];
    for(int w = 2; w <= n-1; ++w)
        for(int i = 1; i <= n-w; ++i) {
            int j = i + w;
            bst[i][j] = 100000000000000000LL;
            for(int k = i; k <= j-1; ++k)
                bst[i][j] = (bst[i][j] > bst[i][k] + bst[k + 1][j] + d[i - 1] * d[k] * d[j]) ? (bst[i][k] + bst[k + 1][j] + d[i - 1] * d[k] * d[j]): bst[i][j];
        }

    fout << bst[1][n];
    return 0;
}