#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("interclasare1.in");
ofstream fout ("interclasare1.out");
int n, m, a[100005], b[100005];
int contor;
int interclasare(int x, int y)
{
    if(x > n || y > m)
        goto endInterclasare;
    if(a[x] < b[y])
    {
        if(contor == 10)
            fout << '\n';
        fout << a[x] << ' ';
        contor++;
        if(a[x+1] == b[y])
            return interclasare(x+2, y);
        return interclasare(x+1, y);
    }
    if(b[y] < a[x])
    {
        if(contor == 10)
            fout << '\n';
        fout << b[y] << ' ';
        contor++;
        if(b[y+1] == a[x])
            return interclasare(x, y+2);
        return interclasare(x, y+1);
    }
    endInterclasare:
    if(x > n)
    {
        if(contor == 10)
            fout << '\n';
        fout << b[y];
        return 0;
    }
    if(contor == 10)
        fout << '\n';
    fout << a[x];
    return 0;
}
int main()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    fin >> m;
    for(int i = 1; i <= m; i++)
        fin >> b[i];
    interclasare(1, 1);
    return 0;
}
