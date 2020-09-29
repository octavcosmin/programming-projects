#include <stdio.h>
#include <algorithm>
#include <vector>

FILE *in, *out;

int main() {
    std::vector<int> array;
    int n;

    // Reading array
    in = fopen("permutari2.in", "r");
    fscanf(in, "%d", &n);
    for(int i = 0; i < n; ++i) {
        int temp;
        fscanf(in, "%d", &temp);
        array.push_back(temp);
    }
    fclose(in);

    // Sorting array
    std::sort(array.begin(), array.end());

    // Generating permutations
    out = fopen("permutari2.out", "w");
    do {
        for(std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
            fprintf(out, "%d ", *it);
        fprintf(out, "\n");
    }while( std::next_permutation(array.begin(), array.end()) );
    fclose(out);

    return 0;
}