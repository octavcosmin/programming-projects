#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string sir;

struct litere {
    char lit;
    int fr;
};
litere frecv[30];

int euro, lung, lmax;

bool inversComp(litere a, litere b) { return a.fr > b.fr; }

int main() {
    cin >> sir >> euro;
    for(int i = 0; i < sir.length(); ++i) {
        ++frecv[sir[i] - 'a'].fr;
        frecv[sir[i] - 'a'].lit = sir[i];
    }

    sort(frecv, frecv+26, inversComp);

    for(int v = 0; v < 26 && frecv[v].fr; ++v) {
        int cost = 0;
        for(int i = 0; i < sir.length(); ++i) {
            int streak = 1;
            while(sir[i] != frecv[v].lit) {
                streak *= 2;
                if(cost + streak > euro) {
                    lung = i-1;
                    break;
                }
                ++i;
            }
            if(streak != 1)
                cost += streak;
            if(cost > euro)
            break;
        }
        lmax = max(lung, lmax);
        if(lmax ==sir.length())
            break;
    }

    cout << lmax+1;
    return 0;
}