#include <bits/stdc++.h>
#define ull long long
#define OO 1000000000000000001

using namespace std;

ifstream fin("abx.in");
ofstream fout("abx.out");

ull n, m, x, solBest;
ull prime[21] = {2,3,5,7,11,13,17,19,23,29,31,37,41,47,51,53,57,59,61};
ull powerMax[21];

/*ull power(ull a, ull b, ull ai) {
    if(b == 1)
        return a;
    if((double )(1000000000000000000/a) < ai)
        return OO + 2 ;
    return power(a*ai, b-1, ai);
}*/

ull power(ull a, ull b) {
    if(b == 1)
        return a;
    if(b%2 == 0) {
        if(a > OO /a)
            return OO;
        return power(a*a, b/2);
    }
    if(a > OO/a)
        return OO;
    ull c = power(a*a, b/2);
    if(c > OO/a)
        return OO;
    return a*c;
}

/*void maxime() {
    for(int i = 0; i < 19; ++i) {
        for(ull j = 1; j <= 64; ++j) {
            ++powerMax[i];
            if((float)power(10, 18, 10)/power(prime[i], j, prime[i]) < prime[i])
                break;
        }
    }
}*/

int main()
{
    //maxime();
    fin >> n >> m;
    for(ull k = 1; k <= n; ++k) {
        fin >> x;
        solBest = 1;
        for(ull i = 0; i < 19; ++i) {
        //fout << solBest << '\n';
            if(power(2,prime[i]) > m)
                break;
            ull left = 2, right = 10000000000, solST = 0;
            while(left <= right) {
                ull mid = (left+right)/2;
                if(power(mid, prime[i]) <= x) {
                    if(power(mid, prime[i]) >= 1 && power(mid, prime[i]) <= m)
                        solST = power(mid, prime[i]);
                    left = mid+1;
                    continue;
                }
                right = mid-1;
            }
            left = 2, right = 10000000000;
            ull solDR = 0;
            while(left <= right) {
                ull mid = (left+right)/2;
                if(power(mid, prime[i]) >= x) {
                    if(power(mid, prime[i]) >= 1 && power(mid, prime[i]) <= m)
                        solDR = power(mid, prime[i]);
                    right = mid-1;
                    continue;
                }
                left = mid+1;
            }
            //fout << solDR << ' ';
            ull solCurent;
            if(solST == 0 && solDR == 0) {
                continue;
            }
            if(solST == 0) {
                solCurent = solDR;
                if(solBest == 0)
                    solBest = solCurent;
                else {
                    if(abs(solCurent-x) < abs(solBest-x))
                        solBest = solCurent;
                    if(abs(solCurent-x) == abs(solBest-x))
                        solBest = min(solBest, solCurent);
                }
                continue;
            }
            if(solDR == 0) {
                solCurent = solST;
                if(solBest == 0)
                    solBest = solCurent;
                else {
                    if(abs(solCurent-x) < abs(solBest-x))
                        solBest = solCurent;
                    if(abs(solCurent-x) == abs(solBest-x))
                        solBest = min(solBest, solCurent);
                }
                continue;
            }
            if(abs(x-solST) >= abs(solDR-x)) {
                solCurent = solDR;
                if(solBest == 0)
                    solBest = solCurent;
                else {
                    if(abs(solCurent-x) < abs(solBest-x))
                        solBest = solCurent;
                    if(abs(solCurent-x) == abs(solBest-x))
                        solBest = min(solBest, solCurent);
                }
                continue;
            }
            solCurent = solST;
            if(solBest == 0)
                solBest = solCurent;
            else {
                if(abs(solCurent-x) < abs(solBest-x))
                    solBest = solCurent;
                if(abs(solCurent-x) == abs(solBest-x))
                    solBest = min(solBest, solCurent);
            }
        }
        fout << solBest << '\n';
    }
    return 0;
}
