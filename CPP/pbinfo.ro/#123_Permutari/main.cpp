#include <stdio.h>

using namespace std;
FILE * in = fopen("permutari.in", "r");
FILE * out = fopen("permutari.out", "w");

int arr[10];
int n, k;

void back(int k) {
    if (k == n) {
        for (int i = 1; i <= n; ++i)
            //fout << arr[i] << ' ';
            fprintf(out, "%d ", arr[i]);
        //fout << "\n";
        fprintf(out, "\n");
        return;
    }

    for (int i = 1; i <= n; ++i) {
        bool ok = true;
        for (int j = 1; j <= k; ++j) {
            if (arr[j] == i) {
                ok = false;
                break;
            }
        }

        if (ok) {
            arr[k+1] = i;
            back(k+1);
        }
    }
}

int main() {
    //fin >> n;
    fscanf(in, "%d", &n);
    
    back(0);

    return 0;
}