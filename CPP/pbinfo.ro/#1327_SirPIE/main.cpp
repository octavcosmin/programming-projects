#include <stdio.h>
#include <vector>
#include <algorithm>

// Pre-declaring funcions
bool check_permutation(std::vector<int> arr);
int Euclid(int a, int b);

FILE *in, *out;

int main() {

    int n;
    std::vector<int> array;

    // Reading array
    in = fopen("sirpie.in", "r");

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
    out = fopen("sirpie.out", "w");

    do {
        if(!check_permutation(array))
            continue;
        for(std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
            fprintf(out, "%d ", *it);
        fprintf(out, "\n");
    }while( std::next_permutation(array.begin(), array.end()) );

    fclose(out);

    return 0;
}

// Functions
bool check_permutation(std::vector<int> arr) {
    for(int i = 1; i < arr.size(); ++i)
        if( Euclid(arr[i-1], arr[i]) > 1 )
            return 0;
    return 1;
}

int Euclid(int a, int b) {
    if(b == 0)
        return a;
    return Euclid(b, a%b);
}