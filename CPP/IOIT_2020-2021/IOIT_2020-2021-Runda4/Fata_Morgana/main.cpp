#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// struct pereche {
//     int first, second;
// };

// bool sort_pereche(pereche a, pereche b) {
//     if(a.first != b.first) return a.first < b.first;
//     else return a.second < b.second;
// }

int n;
vector<int> v;
//vector<pereche> result;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());
    int i = n/2;
    int m = i;
    do {
        ++m;
    }while(v[m] == v[m-1]);
    while(v[i] == v[n-i] && m < n) {
        swap(v[i], v[m]);
        ++m;
        ++i;
        // for(int i = 0; i < n; ++i) {
        //     cout << v[i] << ' ';
        // }
        // cout << '\n';
    }

    // pereche tmp;
    if((n/2) % 2 == 0) {
        for(int i = 0; i < n/2; ++i) {
            // tmp.first = v[i];
            // tmp.second = v[n-1-i];
            // result.push_back(tmp);
            cout << v[i] << ' ' << v[n-1-i] << ' ';
        }
    }
    else {
        for(int i = 1; i < n/2; ++i) {
            // tmp.first = v[i];
            // tmp.second = v[n-1-i];
            // result.push_back(tmp);
            cout << v[i] << ' ' << v[n-1-i] << ' ';
        }
        // tmp.first = v[n-1];
        // tmp.second = v[0];
        // result.push_back(tmp);
        cout << v[n-1] << ' ' << v[0];
    }

    // sort(result.begin(), result.end(), sort_pereche);
    // for(auto it = result.begin(); it != result.end(); ++it) {
    //     cout << it->first << ' ' << it->second << ' ';
    // }

    return 0;
}