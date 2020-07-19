#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ozn.in");
ofstream fout ("ozn.out");

struct data{
    int x1, y1, x2, y2, nr;
};
data ships[20005];

int main()
{
    int N, K;
    fin >> N >> K;
    for(int i = 0; i < N; i++)
        fin >> ships[i].x1 >> ships[i].y1 >> ships[i].x2 >> ships[i].y2 >> ships[i].nr;
    for(int i = 0; i < K; i++)
    {
        int a, kills = 0;
        fin >> a;
        for(int j = 0; j < N; j++)
            if(a >= ships[j].x1 && a <= ships[j].x2)
                kills += ships[j].nr;
        fout << kills << '\n';
    }
    return 0;
}
