#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

// Pre-defining functions
bool check_permutation(std::vector<int> arr);
void print_chess_board(int board_size, std::vector<int> arr);

int main() {
    int n;
    std::vector<int> array;

    // Reading n and generating the array
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        array.push_back(i);

    // Generating and checking permutations
    do {
        if(check_permutation(array)) {
            print_chess_board(n, array);
            return 0;
        }
    }while( std::next_permutation(array.begin(), array.end()) );
    
    return 0;
}

// Functions
bool check_permutation(std::vector<int> arr) {
    for(int i = 0; i < arr.size()-1; ++i)
        for(int j = i+1; j < arr.size(); ++j)
            if(abs(arr[i] - arr[j]) == abs(i - j))
                return 0;
    return 1;
}

void print_chess_board(int board_size, std::vector<int> arr) {
    for(int i = 0; i < arr.size(); ++i) {
        for(int j = 1; j <= board_size; ++j) {
            if(j == arr[i])
                printf("* ");
            else
                printf("- ");
        }
        printf("\n");
    }
}