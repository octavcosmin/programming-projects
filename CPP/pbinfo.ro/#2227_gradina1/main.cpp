#include <bits/stdc++.h>

using namespace std;
const int NMMAX = 50 +5;
const int SMAX = 100 +5;

int N, M, S;
int plantate[NMMAX][NMMAX], umidMax[NMMAX][NMMAX], umidMin[SMAX];

int main()
{
    ///CITIRE
    scanf("%d%d%d", &N, &M, &S);

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            scanf("%d", &plantate[i][j]);

    for(int i = 1; i <= S; ++i)
        scanf("%d", &umidMin[i]);

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            scanf("%d", &umidMax[i][j]);
    return 0;
}
