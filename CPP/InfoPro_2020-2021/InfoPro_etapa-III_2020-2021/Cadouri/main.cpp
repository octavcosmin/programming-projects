#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool by_size(pair<int,int> a, pair<int,int> b) {
    return a.first < b.first;
}

vector<pair<int,int>> srt;
int solve(int N, long long K, int cnt[], int m[]) {
    freopen("cadouri.out", "w", stdout);

    for(int i = 1; i <= N; ++i)
        srt.push_back(pair<int,int>(m[i], cnt[i]));
    sort(srt.begin(), srt.end(), by_size);

    long long numarare{0};
    for(int i = 0; i < N; ++i) {
        numarare += srt[i].second;
        if(numarare >= K) {
            printf("%d", srt[i].first);
            return 0;
        }
    }
    return 0;
}

// DE SCOS PENTRU TRIMITERE
int N, K, cnt[5000005], m[5000005];
int main() {
    freopen("cadouri.in", "r", stdin);

    scanf("%d%d", &N, &K);
    for(int i = 1; i <= N; ++i)
        scanf("%d%d", &cnt[i], &m[i]);
    solve(N, K, cnt, m);
    return 0;
}