#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("frecventa1.in");
ofstream fout("frecventa1.out");

bool pairSort(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int n;
vector<pair<int,int>> fr(100);

int main() {
    fin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        fin >> x;
        fr[x].first = x;
        ++fr[x].second;
    }

    sort(fr.begin(), fr.end(), pairSort);

    for(auto it = fr.begin(); it != fr.end() && it->first; ++it)
        fout << it->first << ' ';
    return 0;
}