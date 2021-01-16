#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct girl {
    int points, chance;
    double coef;
};

vector<girl> v;
int n, swipes, result;

bool comp(girl a, girl b) {
    if(a.coef != b.coef) return a.coef > b.coef;
    else return a.points < b.points;
}

int main() {
    // Citire
    cin >> n >> swipes;

    for(int i = 0; i < n; ++i) {
        girl tmp;
        cin >> tmp.chance >> tmp.points;
        tmp.coef = (double)tmp.chance/tmp.points;

        v.push_back(tmp);
    }

    // Sortare dupa coeficient (sanse/puncte)
    sort(v.begin(), v.end(), comp);

    // for(int i = 0; i < n; ++i) {
    //     cout << v[i].coef << ' ' << v[i].chance << ' ' << v[i].points << '\n';
    // }

    int used{0};
    for(int i = 0; i < n && used < swipes; ++i) {
        if(used + v[i].points <= swipes) {
            used += v[i].points;
            result += v[i].chance;
        }
        if(used == swipes) break;
    }

    cout << result;
}