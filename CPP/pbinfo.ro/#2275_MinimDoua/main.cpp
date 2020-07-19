#include <bits/stdc++.h>

using namespace std;

ifstream fin("minimdoua.in");
ofstream fout("minimdoua.out");

int n, minim1 = INT_MAX, minim2 = INT_MAX;

int main()
{
    fin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        fin >> x;
        if(x > 9 && x%10 == x/10%10) {
            if(x < minim1) {
                minim2 = minim1;
                minim1 = x;
                continue;
            }
            if(x < minim2) {
                minim2 = x;
                continue;
            }
        }
    }
    if(minim1 != INT_MAX && minim2 != INT_MAX)
        fout << minim1 << ' ' << minim2;
    else
        fout << "numere insuficiente";
    return 0;
}
