#include <stdio.h>
#include <vector>

using namespace std;

FILE *in, *out;
int n, value, left, right;
vector<int> leafs;

int main() {

// Reading the binary tree
    in = fopen("bifrunze.in", "r");
    fscanf(in, "%d", &n);
    for(int i = 1; i <= n; ++i) {
        fscanf(in, "%d%d%d", &value, &left, &right);
        if(!left && !right)
            leafs.push_back(i);
    }
    fclose(in);

    out = fopen("bifrunze.out", "w");
    for(int i = 0; i < leafs.size(); ++i)
        fprintf(out, "%d ", leafs[i]);
    fclose(out);
    return 0;
}