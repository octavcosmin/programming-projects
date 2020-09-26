#include <stdio.h>


// STRUCTURES
struct coordinates {
    int row, line;

    coordinates operator+(const coordinates& coord) {
        coordinates result;
        result.row = this->row + coord.row;
        result.line = this->line + coord.line;
        return result;
    }
    bool operator==(const coordinates& comp) {
        return ((this->row == comp.row) && (this->line == comp.line));
    }
};

// VARIABLES
coordinates matrix_size, start, finish;
int matrix[15][15];
int alternative_ways;

// CONSTANTS
const coordinates direction[] = {{0, -1}, {+1, 0}, {0, +1}, {-1, 0}};

// PRE-DEFINE FUNCTIONS
void beading();
int backtracking(coordinates position, int matrix[][15], int __layer);
void duplicate_matrix(int m1[][15], int m2[][15]);

int main() {
    // REOPEN 'stdin' AND 'stdout'
    freopen("soarece.in", "r", stdin);
    freopen("soarece.out", "w", stdout);

    scanf("%d%d", &matrix_size.line, &matrix_size.row);
    for(int i = 1; i <= matrix_size.line; ++i)
        for(int j = 1; j <= matrix_size.row; ++j)
            scanf("%d", &matrix[i][j]);
    scanf("%d%d%d%d", &start.line, &start.row, &finish.line, &finish.row);

    beading();
    for(int i = 0; i < 15; ++i, printf("\n"))
        for(int j = 0; j < 15; ++j)
            printf("%d ", matrix[i][j]);
    printf("\n");

    printf("%d", backtracking(start, matrix, 0));
    return 0;
}

void TMPafisare_matrice() {
    for(int i = 1; i <= matrix_size.line; ++i, printf("\n"))
        for(int j = 1; j <= matrix_size.row; ++j)
            printf("%d ", matrix[i][j]);
    printf("\n");
}

// FUNCTIONS
void beading() {
    for(int i = 0; i <= matrix_size.line; ++i)
        matrix[i][0] = matrix[i][matrix_size.row+1] = 1;
    for(int j = 0; j <= matrix_size.row; ++j)
        matrix[0][j] = matrix[matrix_size.line+1][j] = 1;
}

void duplicate_matrix(int m1[][15], int m2[][15]) {
    for(int i = 1; i <= matrix_size.line; ++i)
        for(int j = 1; j <= matrix_size.row; ++j)
            m2[i][j] = m1[i][j];
}

int backtracking(coordinates position, int matrix[][15], int __layer) {

    if(position == finish)
        return 1;

    matrix[position.line][position.row] = 1;

    for(int d = 0; d < 4; ++d) {
        coordinates next = position + direction[d];
        if(next == finish)
            return 1;
        if(!matrix[next.line][next.row]) {
            int matrix_copy[15][15];
            duplicate_matrix(matrix, matrix_copy);
            alternative_ways += backtracking(next, matrix_copy, __layer+1);
            TMPafisare_matrice();
        }
    }
    return alternative_ways;
}