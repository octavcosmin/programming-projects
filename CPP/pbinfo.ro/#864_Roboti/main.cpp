#include <fstream>
using namespace std;

ifstream fin("roboti.in");
ofstream fout("roboti.out");

int n, m, mat[1005][1005], i, j, prim, ultim;

struct Coord {
    int x, y;
};
Coord q[100005], s, f;

int main() {
    fin >> n >> m;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            fin >> mat[i][j];
    fin >> s.y >> s.x >> f.y >> f.x;

    prim = 1;
    q[++ultim] = s;


    return 0;
}