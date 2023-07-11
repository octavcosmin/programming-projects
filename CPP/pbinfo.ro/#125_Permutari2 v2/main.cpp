#include <iostream>
using namespace std;

typedef int array10[10];

void print_solution(int n, array10 solution, array10 numbers) {
    for(int i = 1; i <= n; ++i)
        cout << numbers[ solution[i] ] << ' ';
    cout << '\n';
}
bool validate_solution(int depth, int current_value, array10 solution) {
    for(int i = 1; i <= depth; ++i)
        if(solution[i] == current_value)
            return 0;
    return 1;
}

void permutations(int depth, int n, array10 numbers) {
    static array10 solution;
    if(depth == n) {
        print_solution(n, solution, numbers);
        return;
    }

    for(int i = 1; i <= n; ++i) {
        if(validate_solution(depth, i, solution)) {
            solution[depth+1] = i;
            permutations(depth+1, n, numbers);
        }
    }
}

void bubble_sort(array10 &arr, int size) {
    for(int i = 1; i < size; ++i)
        for(int j = i+1; j <= size; ++j)
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

int main() {
    freopen64("permutari2.in", "r", stdin);
    freopen64("permutari2.out", "w", stdout);

    array10 v;
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; ++i) cin >> v[i];
    bubble_sort(v, n);
    permutations(0, n, v);
    return 0;
}