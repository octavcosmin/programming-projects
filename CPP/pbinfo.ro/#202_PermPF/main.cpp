#include <stdio.h>
#include <vector>
#include <algorithm>

// Pre-defining functions
bool check_permutation(std::vector<int> arr);

FILE *in, *out;

int main() {
    // Variables
    int n;
    std::vector<int> array;

    // Reading n and generating array
    in = fopen("permpf.in", "r");

    fscanf(in, "%d", &n);
    for(int i = 1; i <= n; ++i)
        array.push_back(i);

    fclose(in);

    // Generating and checking permutations
    out = fopen("permpf.out", "w");

    do {
        if(check_permutation(array)) {
            for(std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
                fprintf(out, "%d ", *it);
            fprintf(out, "\n");
        }
    }while( std::next_permutation(array.begin(), array.end()) );

    fclose(out);

    return 0;
}

bool check_permutation(std::vector<int> arr) {
    for(int i = 0; i < arr.size(); ++i)
        if(arr[i] == i+1)
            return 0;
    return 1;
}