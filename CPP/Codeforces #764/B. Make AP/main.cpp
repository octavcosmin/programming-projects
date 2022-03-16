#include <cstdio>
#include <vector>

using namespace std;

bool solve(vector<int> arr);

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t) {
        vector<int> tmp(3);
        scanf("%d %d %d", &tmp[0], &tmp[1], &tmp[2]);

        if(solve(tmp)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

bool solve(vector<int> arr) {
    // CHECK IF IT IS AP
    if(arr[2] == 2*arr[1] - arr[0]) return 1;

    /// CHANGING THE FIRST NUMBER
    if(2*arr[1] - arr[2] > 0 && (2*arr[1] - arr[2]) % arr[0] == 0) return 1;

    /// CHANGING THE SECOND NUMBER
    if(arr[0] + arr[2] > 0 && (arr[0] + arr[2]) % (2*arr[1]) == 0) return 1;

    /// CHANGING THE THIRD NUMBER
    if(2*arr[1] - arr[0] > 0 && (2*arr[1] - arr[0]) % arr[2] == 0) return 1;

    return 0;
}