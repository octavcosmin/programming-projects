#include <bits/stdc++.h>

using namespace std;

ifstream fin("platou1.in");
ofstream fout("platou1.out");

int lmax, lcurent, nr;

int main()
{
    int x, prevX;
    fin >> prevX;
    lcurent = 1, nr = prevX;
    while(fin >> x) {
        if(x == prevX)
            ++lcurent;
        else {
            if(lcurent > lmax || (lcurent == lmax && prevX < nr)) {
                lmax = lcurent;
                nr = prevX;
            }
            lcurent = 1;
        }
        prevX = x;
    }

    fout << lmax << ' ' << nr;
    return 0;
}
