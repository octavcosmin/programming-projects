#include <iostream>

using namespace std;

int T, n, hill[100005], xmax;

int main() {
    cin >> T;
    for(int t = 0; t < T; ++t) {
        cin >> n;
        xmax = 0;
        
        for(int i = 0; i < n; ++i) {
            cin >> hill[i];
            xmax = max(hill[i], xmax);
        }
    }
    return 0;
}