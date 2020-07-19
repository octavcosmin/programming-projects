#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("zmeu.in");
ofstream fout("zmeu.out");

int main()
{
    long long n,m;
    fin >> n >> m;
    m = 2*m;
    fout << n/m << '\n' << m-n%m;
    return 0;
}
