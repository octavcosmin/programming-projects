#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ozn.in");
ofstream fout ("ozn.out");

int alienNumber[2000005];

void logAliens(int x1, int x2, int nr)
{
    for(int i = x1; i <= x2; i++)
        alienNumber[i] += nr;
}

int main()
{
    int N,K;
    fin >> N >> K;
    for(int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2, nr;
        fin >> x1 >> y1 >> x2 >> y2 >> nr;
        logAliens(x1, x2, nr);
    }
    for(int i = 0; i < K; i++)
    {
        int a;
        fin >> a;
        fout << alienNumber[a] << '\n';
    }
    return 0;
}
