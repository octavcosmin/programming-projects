#include <iostream>
using namespace std;
int n, i, r;
int main() {
    cin >> n;
    cout << n/5 + (bool)(n%5) << '\n' << (n % 5 == 0 ? "DA" : "NU") << '\n';
    for(i = 1; r < n/5 + (bool)(n%5); ++i)
        r += i;
    cout << (i % 2 ? "panselute" : "micsunele");
    return 0;
}