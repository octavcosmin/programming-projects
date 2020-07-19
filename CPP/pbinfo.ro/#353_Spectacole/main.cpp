#include<bits/stdc++.h>

using namespace std;

ifstream in("spectacole.in");
ofstream out("spectacole.out");

struct myType {
    int start, stop;
};
vector<myType> spectacol;
myType temp;

int n;

bool compTime(myType x, myType y) {
    if(x.stop < y.stop)
        return 1;
    if(x.stop == y.stop && x.stop - x.start < y.start - y.stop)
        return 1;
    return 0;
}

int parcurgere(int i, int last, int nrSpect) {
    if(i == n)
        return nrSpect;
    if(spectacol[i].start >= last)
        return parcurgere(i+1, spectacol[i].stop, nrSpect+1);
    return parcurgere(i+1, last, nrSpect);
}

int main()
{
    in >> n;
    int i = n;
    while(i--) {
        in >> temp.start >> temp.stop;
        spectacol.push_back(temp);
    }
    sort(spectacol.begin(), spectacol.end(), compTime);

    /*for(int i = 0; i < n; ++i) {
        out << spectacol[i].start << ' ' << spectacol[i].stop << '\n';
    }*/
    out << parcurgere(0, 0, 0);
    return 0;
}
