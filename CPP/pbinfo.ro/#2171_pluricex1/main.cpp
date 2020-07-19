#include <bits/stdc++.h>

using namespace std;

int N, K, D;
vector<int> elevi[25], solutie(25);
bool fr[11];

bool verificare() {
    for(int i = 1; i <= D; ++i)
        fr[i] = false;
    for(int i = 1; i <= N; ++i)
        for(auto it = elevi[solutie[i]].begin(); it != elevi[solutie[i]].end(); ++it)
            fr[*it] = true;
    for(int i = 1; i <= D; ++i)
        if(fr[i] == false)
            return 0;
    return 1;
}

void rezolvare() {
    for(int i = 1; i <= K; ++i)
        solutie[i] = i;
    while(1) {
        if(verificare())
            for()
    }
}

int main()
{
    ///CITIRE
    scanf("%d%d%d", &N, &K, &D);
    for(int i = 1; i <= N; ++i) {
        int nrd;
        scanf("%d", &nrd);
        for(int j = 1; j <= nrd; ++j) {
            int temp;
            scanf("%d", &temp);
            elevi[i].push_back(temp);
        }
    }


    return 0;
}
