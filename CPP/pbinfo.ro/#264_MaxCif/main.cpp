#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

pair<short,int> frec[10];

bool pairSort(pair<short,int> a, pair<short,int> b) {
    if(a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main() {
    freopen("maxcif.in", "r", stdin);
    freopen("maxcif.out", "w", stdout);

    int tmp;
    while(scanf("%d", &tmp) == 1) {
        ++frec[tmp].first;
        frec[tmp].second = tmp;
    }

    sort(frec, frec + 10, pairSort);

    printf("%d ", frec[9].second);
    for(int i = 8; i >= 0; --i) {
        if(frec[i].first != frec[i+1].first)
            return 0;
        printf("%d ", frec[i].second);
    }
    return 0;
}