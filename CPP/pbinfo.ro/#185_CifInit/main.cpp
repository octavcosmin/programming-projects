#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> arr;
int n, x;

int power10(int e) {
    int rez{1};
    for(int i = 1; i <= e; ++i)
        rez *= 10;

    return rez;
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        arr.push_back(x/power10(log10(x)));
    }

    sort(arr.begin(), arr.end());

    for(vector<int>::iterator it = arr.begin(); it != arr.end(); ++it)
        printf("%d", *it);
    return 0;
}