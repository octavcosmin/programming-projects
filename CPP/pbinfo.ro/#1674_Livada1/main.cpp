#include <bits/stdc++.h>
#define ll long long

using namespace std;

//ifstream in("livada1.in");
//ofstream out("livada1.out");
FILE *in = fopen("livada1.in", "r");
FILE *out = fopen("livada1.out", "w");

ll n, m, c, r;
ll x, y, z, w, u;
ll A[105][25005], val_max[105][25005];
ll suma[105][25005];
ll kgMax;
vector<ll> scol;

bool test(int x) {
    for(int i = 1; i <= n; ++i) {
        int st = 1, dr = m, mid, sol=m+1;
        while(st <= dr) {
            mid = (st+dr)/2;
            if(val_max[i][mid] > x) {
                sol = mid;
                dr = mid-1;
            }
            else
                st = mid+1;
        }
        sol--;
        scol.push_back(suma[i][sol]);
    }
    sort(scol.begin(), scol.end());
    ll sumR = 0;
    /*cout << x << '\n' ;
    for (int i = 0; i < n; ++i)
        cout << scol[i] << ' ';
    cout << '\n';*/
    for(int i = n-1; i >= n-r; --i)
        sumR += scol[i];
    scol.clear();
    if(sumR < c)
        return 0;
    return 1;
}

int main()
{
  //  in >> n >> m >> c >> r;
   // in >> x >> y >> z >> w >> u;
    fscanf(in, "%lld%lld%lld%lld%lld%lld%lld%lld%lld", &n, &m, &c, &r, &x, &y, &z, &w, &u);
    for(int j = 1; j <= m; ++j) {
     //   in >> A[1][j];
        fscanf(in,"%lld", &A[1][j]);
        kgMax = max(A[1][j], kgMax);
    }
    for(int i = 2; i <= n; ++i) {
      //  in >> A[i][1];
        fscanf(in,"%lld", &A[i][1]);
        kgMax = max(A[i][1], kgMax);
    }
    for(int i = 1; i <= n; ++i)
        val_max[i][1] = A[i][1], suma[i][1] = A[i][1];
    for(int j = 2; j <= m; ++j)
        val_max[1][j] = max(val_max[1][j-1], A[1][j]), suma[1][j] = suma[1][j-1] + A[1][j];
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            A[i][j] = (ll)(x*A[i-1][j] + y*A[i][j-1] + z*A[i-1][j-1] + w) % u;
            kgMax = max(A[i][j], kgMax);
            val_max[i][j] = max(val_max[i][j-1], A[i][j]);
            suma[i][j] = suma[i][j-1] + A[i][j];
        }
    }
    /*for(int i = 1; i <= n; ++i, cout << '\n') {
        for(int j = 1; j <= m; ++j) {
            cout << val_max[i][j] << ' ';
        }
    }*/
    int st = 1, dr = kgMax, mid, sol = -1;
    while(st <= dr) {
        mid = (st+dr)/2;
        if(test(mid)) {
            sol = mid;
            dr = mid-1;
        }
        else
            st = mid+1;
    }
    fprintf(out,"%d",sol);
    return 0;
}
