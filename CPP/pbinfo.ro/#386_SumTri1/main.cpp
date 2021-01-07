#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int NMAX = 100 +5;
int n, result = 100000 +5, current_sum_min;
int tri[NMAX][NMAX], smin[NMAX][NMAX];
vector<int> path, temp_path;

int sum_min(int i, int j);

int main() {
    freopen("sumtri1.in", "r", stdin);
    freopen("sumtri1.out", "w", stdout);

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            scanf("%d", &tri[i][j]);

            if(i == n) {
                temp_path.clear();
                current_sum_min = sum_min(i, j);

                if(result > current_sum_min) {
                    result = current_sum_min;
                    path = temp_path;
                    path.push_back(tri[i][j]);
                }
            }
        }
    }

    printf("%d\n", result);

    for(auto it = path.begin(); it != path.end(); ++it)
        printf("%d ", *it);
    return 0;
}

int sum_min(int i, int j) {
    if(smin[i][j])
        return smin[i][j];

    if(i == 1 && j == 1)
        smin[i][j] = tri[i][j];
    else {
        if(j == i) {
            smin[i][j] = tri[i][j] + sum_min(i-1, j-1);
            temp_path.push_back(tri[i-1][j-1]);
            goto skip;
        }
        if(j == 1) {
            smin[i][j] = tri[i][j] + sum_min(i-1, j);
            temp_path.push_back(tri[i-1][j]);
            goto skip;
        }

        int temp1_sum_min = sum_min(i-1, j), temp2_sum_min = sum_min(i-1, j-1);
        if(temp1_sum_min < temp2_sum_min) {
            smin[i][j] = tri[i][j] + temp1_sum_min;
            temp_path.push_back(tri[i-1][j]);
        }
        else {
            smin[i][j] = tri[i][j] + temp2_sum_min;
            temp_path.push_back(tri[i-1][j-1]);
        }
        // smin[i][j] = tri[i][j] + min(sum_min(i-1, j), sum_min(i-1, j-1));
    }
    skip:
    return smin[i][j];
}