#include <cstdio>
#include <iostream>

#define KMAX 20
#define NMAX 200001

using namespace std;

int nxt[NMAX], dp[NMAX], sp[NMAX], box[NMAX], vc[KMAX], P, n, k, t;
char a[NMAX][KMAX];
void reset() {
    for(int i = 1; i <= n+1; ++i) {
        nxt[i] = box[i] = dp[i] = 0;
        for (int j = 0; j < k; ++j)
            a[i][j] = 0;
    }
    for(int i = 0; i < k; ++i)
        vc[i] = 0;
}
int main() {

    freopen("bob.in", "r", stdin);
    freopen("bob.out", "w", stdout);

    scanf("%d%d", &P, &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        nxt[n+1] = n + 1;
        dp[n+1] = 1;
        sp[n+1] = 1;
        sp[n+2] = dp[n+2] = 0;
        for(int i = n; i; i--) {
            bool ok = 1;
            for(int j = 0; j < k; ++j) {
                if (a[i][j] == '1')
                    vc[j]++;
                if (!vc[j])
                    ok = 0;
            }
            if(!ok)
                nxt[i] = n + 1;
            int j2 = nxt[i+1];
            while(ok) {
                for(int j = 0; j < k; ++j)
                    if (a[j2][j] == '1' && vc[j] == 1)
                        ok = 0;
                if (!ok)
                    break;
                for(int j = 0; j < k; ++j)
                    if (a[j2][j] == '1')
                        vc[j]--;
                j2--;
            }
            if(!nxt[i])
                nxt[i] = j2;
            if(nxt[i] <= n)
                box[i] = box[nxt[i]+1] + 1;
            else
                box[i] = 0;
            int st = 1 + nxt[i], dr = n + 1;
            int x1 = -1;
            int x = box[i] - 1;
            while(st <= dr) {
                int mid = (st + dr) / 2;
                if(box[mid] == x) {
                    x1 = mid;
                    dr = mid - 1;
                }
                else
                if(box[mid] < x)
                    dr = mid - 1;
                else
                    st = mid + 1;
            }
            st = 1 + nxt[i], dr = n + 1;
            int x2 = -1;
            while(st <= dr) {
                int mid = (st + dr) / 2;
                if(box[mid] == x) {
                    x2 = mid;
                    st = mid + 1;
                }
                else
                if(box[mid] < x)
                    dr = mid - 1;
                else
                    st = mid + 1;
            }
            dp[i] = (sp[x1] - sp[x2 + 1]);
            if(dp[i] < 0)
                dp[i] += 1000000007;
            sp[i] = (sp[i + 1] + dp[i]) % 1000000007;
        }
        if(P == 1) {
            printf("%d\n", box[1]);
            reset();
        }
        else {
            printf("%d\n", dp[1]);
            reset();
        }
    }
    return 0;
}