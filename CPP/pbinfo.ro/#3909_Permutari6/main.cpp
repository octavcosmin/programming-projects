#include <iostream>
using namespace std;

typedef int array10[10];

int A, B, n;
array10 solution;

void print_solutions() {
    for(int i = 1; i <= n; ++i)
        cout << solution[i] + A-1 << ' ';
    cout << '\n';
}

bool validate_solution(int depth, int current_value) {
    for(int i = 1; i <= depth; ++i)
        if(solution[i] == current_value)
            return 0;
    return 1;
}

void permutations(int depth) {
    if(depth == n) {
        print_solutions();
        return;
    }

    for(int i = 1; i <= n; ++i)
        if(validate_solution(depth, i)) {
            solution[depth+1] = i;
            permutations(depth+1);
        }
}

int main() {
    // freopen64("permutari6.in", "r", stdin);
    // freopen64("permutari6.out", "w", stdout);

    cin >> A >> B;
    n = B-A + 1; // 6-4 + 1 = 3; {4, 5, 6}
    permutations(0);
    return 0;
}