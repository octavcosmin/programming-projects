#include <iostream>
using namespace std;
void Impare(int &n);

int main() {
    int n;
    cin >> n;
    Impare(n);
    cout << n;
    return 0;
}

void Impare(int &n) {
    int nr[11]{0,0,0,0,0,0,0,0,0,0,0}, k{1};
    while(n) {
        nr[k++] = n%2 ? n%10-1 : n%10;
        n /= 10;
    }
    while(k-- > 1)
        n = n*10 + nr[k];
}