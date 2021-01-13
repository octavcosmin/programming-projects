#include <iostream>
#include <cstdio>

#define MAXIM 100000 +5

using namespace std;

int n, v[MAXIM], m, pozitie, rep;
bool relevante[MAXIM];

// int operatiaS(int elim) {
//     int maxim{0};
//     int rep{0};

//     for(int i = 1; i <= n; ++i) {
//         if(i == elim)
//             continue;

//         if(v[i] > maxim) 
//             maxim = v[i];
//         else
//             if(v[i] == maxim)
//                 ++rep;
//     }

//     return rep;
// }

int main() {

    freopen("maxime.in", "r", stdin);
    freopen("maxime.out", "w", stdout);

    cin >> n;
    int maxim{0}, poz1{0};
    for(int i = 1; i <= n; ++i) {
        cin >> v[i];
        if(v[i] > maxim) {
            maxim = v[i];
            poz1 = i;
            //relevante[i] = true;
        }
        else
            if(v[i] == maxim) {
                ++rep;
                relevante[i] = true;
                relevante[poz1] = true;
                poz1 = 0;
            }
    }

    for(int i = 1; i <= n; ++i)
        cout << v[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; ++i)
        cout << relevante[i] << ' ';
    cout << '\n';

    cin >> m;
    for(int i = 1; i <= m; ++i) {
        cin >> pozitie;
        if(relevante[pozitie])
            cout << rep-1 << ' ';
        else
            cout << rep << ' ';
        
    }

    return 0;
}