#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main() {
    freopen("cifreord.in", "r", stdin);
    freopen("cifreord.out", "w", stdout);

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        if(distance(arr.begin(), it)  % 20 == 0 && it != arr.begin())
            printf("\n");
        printf("%d ", *it);
    }
    return 0;
}