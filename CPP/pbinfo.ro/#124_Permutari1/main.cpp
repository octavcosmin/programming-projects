#include <stdio.h>
#include <vector>
#include <algorithm>

FILE *in, *out;

int main() {
    int n;
    std::vector<int> array;

    // Read from file
    in = fopen("permutari1.in", "r");
    fscanf(in, "%d", &n);
    fclose(in);

    // Fill array with numbers n to 1
    for(int i = n; i >= 1; --i)
        array.push_back(i);

    // Output permutations
    out = fopen("permutari1.out", "w");
    do {
        for(std::vector<int>::iterator i = array.begin(); i != array.end(); ++i)
            fprintf(out, "%d ", *i);
        fprintf(out, "\n");
    }while( std::prev_permutation(array.begin(), array.end()) );
    return 0;
}