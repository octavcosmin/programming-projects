#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> arr);

int main() {
    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; ++t) {
        int n;
        scanf("%d", &n);
        vector<int> tmp(n, 0);
        for(int i = 0; i < n; ++i)
            scanf("%d", &tmp[i]);

        printf("%d\n", solve(tmp));
    }
    return 0;
}

int solve(vector<int> arr) {
    sort(arr.begin(), arr.end());

    // printf("\n");
    // for(auto it = arr.begin(); it != arr.end(); ++it)   printf("%d ", *it);
    // printf("\n");

    int sol{0};
    for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it) {
        if(it == arr.begin())
            continue;
        if(*it != *(it-1))
            sol += *it - *(it-1);
    }

    return sol;
}