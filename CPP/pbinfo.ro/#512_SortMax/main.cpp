#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool invers(int a, int b) { return a > b;}

int n, elemMax, pozMax;
vector<int> arr;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp > elemMax) {
            elemMax = tmp;
            pozMax = i;
        }
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.begin() + pozMax);
    sort(arr.begin() + pozMax+1, arr.end(), invers);

    for(auto it = arr.begin(); it != arr.end(); ++it)
        printf("%d ", *it);
    return 0;
}