#include <bits/stdc++.h>

using namespace std;

struct myType {
    int greutate, valoare;
};
vector<myType> obiect;
myType temp;

int n, gMax;

bool myComp(myType x, myType y) {
    if((double)x.valoare/x.greutate > (double)y.valoare/y.greutate)
        return 1;
    return 0;
}

/*int parcurgere(int i, double rez, int g) {
    if(g == 0 || i == n)
        return rez;
    if(obiect[i].greutate <= g)
        return parcurgere(i+1, rez+obiect[i].valoare, g-obiect[i].greutate);
    return rez+obiect[i].valoare*((double)g/obiect[i].greutate);
}*/

int main()
{
    cin >> n >> gMax;
    int i = n;
    while(i--) {
        cin >> temp.greutate >> temp.valoare;
        obiect.push_back(temp);
    }
    sort(obiect.begin(), obiect.end(), myComp);

    int rez = 0;
    for(int i = 0; i < n; ++i) {
        if(gMax <= 0)
            break;
        if(obiect[i].greutate <= gMax) {
            gMax -= obiect[i].greutate;
            rez += obiect[i].valoare;
            continue;
        }
        rez += obiect[i].valoare*((double)gMax/obiect[i].greutate);
        break;
    }
    cout << rez;
    return 0;
}
