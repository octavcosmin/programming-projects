#include <bits/stdc++.h>

using namespace std;

ifstream in("flori2.in");
ofstream out("flori2.out");

int flori[155][155];
vector<int> intersectie;
vector<int>::iterator it;
bool inPereche[155];
int n, k;

int main()
{
    in >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            in >> flori[i][j];
        }
        sort(flori[i] + 1, flori[i] + 1 + k);
    }

    int t = 1;
    while(t <= n) {
        if(inPereche[t]) {
            ++t;
            continue;
        }

        for(int i = t+1; i <= n; i++) {
            if(!inPereche[i]) {
                it = set_intersection(flori[t] + 1, flori[t] + 1 + k, flori[i] + 1, flori[i] + 1 + k, intersectie.begin());
                intersectie.resize(it - intersectie.begin());
                if(intersectie.size()) {
                    inPereche[i] = 1;
                    out << i << ' ';
                }
            }
        }
        out << '\n';
    }
    return 0;
}
