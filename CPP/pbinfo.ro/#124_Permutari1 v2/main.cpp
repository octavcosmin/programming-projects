#include <iostream>

using namespace std;

typedef int array10[10];
array10 solution;

void print_solution(int n) {
    for(int i = 1; i <= n; ++i)
        cout << solution[i] << ' ';
    cout << '\n';
}
bool validate_solution(int depth, int current_value) {
    for(int i = 1; i <= depth; ++i)
        if(solution[i] == current_value)
            return 0;
    return 1;
}

void perm(int depth, int n) {
    if(depth == n) {
        print_solution(n);
        return;
    }

    for(int i = n; i >= 1; --i) {
        if(validate_solution(depth, i)) {
            solution[depth+1] = i;
            perm(depth+1, n);
        }
    }
}

int main() {
    freopen("permutari1.in", "r", stdin);
    freopen("permutari1.out", "w", stdout);
    int n;

    cin >> n;
    perm(0, n);

    return 0;
}