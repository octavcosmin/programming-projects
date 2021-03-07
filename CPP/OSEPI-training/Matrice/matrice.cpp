#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int NMAX = 405;

int N, mat[NMAX][NMAX], partial[NMAX][NMAX], found;
vector<int> sume;

FILE *in, *out;

int main() {
    in = fopen("matrice.in", "r");
    fscanf(in, "%d", &N);
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            fscanf(in, "%d", &mat[i][j]);

            partial[i][j] = mat[i][j] + partial[i-1][j] + partial[i][j-1] - partial[i-1][j-1];
        }
    }
    fclose(in);

    for(int i = 1, j = 1; i <= N && j <= N; ++i, ++j) {
        int i2 = N - i + 1;
        int j2 = N - j + 1;
        //Diagonala stanga sus -> dreapta jos
        sume.push_back(partial[i][j]);

        //Diagonala dreapta sus -> stanga jos
        sume.push_back(partial[i][N] - partial[i][j2-1]);

        //Diagonala stanga jos -> dreapta sus
        sume.push_back(partial[N][j] - partial[i2-1][j]);

        //Diagonala dreapta jos -> stanga sus
        sume.push_back(partial[N][N] - partial[N][j2-1] - partial[i2-1][N] + partial[i2-1][j2-1]);
    }
    sort(sume.begin(), sume.end());

    // for(auto it = sume.begin(); it != sume.end(); ++it)
    //     printf("%d ", *it);
    // printf("\n");
    // for(auto it = valMat.begin(); it != valMat.end(); ++it)
    //     printf("%d ", *it);

    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(binary_search(sume.begin(), sume.end(), mat[i][j]))
                ++found;
        }
    }
    // for(auto it = valMat.begin(); it != valMat.end(); ++it)
    //     if(binary_search(sume.begin(), sume.end(), *it))
    //         ++found;

    out = fopen("matrice.out", "w");
    fprintf(out, "%d", found);
    fclose(out);
    return 0;
}