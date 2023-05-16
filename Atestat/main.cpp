#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ofstream fout("matrice.out");

int a[1001][1001];

bool checkSquare(int x) {
    if(sqrt(x) == (int)sqrt(x)) 
        return 1;
    return 0;
}

bool checkPrime(int x) {
    if(x == 1)
        return 0;
    if(x == 2)
        return 1;
    for(int d = 2; d*d <= x; ++d)
        if(x % d == 0)
            return 0;
    return 1;
}

int main()
{
    int m;
    cin >> m;
    
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= m; ++j) {
            int tmp = i*i + j*j;
            if(checkSquare(tmp)) {
                a[i][j] = 1;
                continue;
            }
            if(checkPrime(tmp) && tmp > 2) {
                a[i][j] = 2;
                continue;
            }
            a[i][j] = 3;
        }
        
    for(int i = 1; i <= m; ++i, fout << '\n')
        for(int j = 1; j <= m; ++j)
            fout << a[i][j] << ' ';
    return 0;
}
