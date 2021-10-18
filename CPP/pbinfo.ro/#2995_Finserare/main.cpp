#include <iostream>
using namespace std;
void inserare(int &n);

int main() {
    int n;
    cin >> n;
    inserare(n);
    cout << n;
    return 0;
}

void inserare(int &n) {
    int nr[10]{0,0,0,0,0,0,0,0,0,0}, k{0};
    while(n) {
        nr[k++] = n%10;
        nr[k++] = n%10 > n%100/10 ? n%10 - n%100/10 : n%100/10 - n%10;
        n /= 10;
    }
    --k;
    while(k-- > 0)
        n = n*10 + nr[k];
}