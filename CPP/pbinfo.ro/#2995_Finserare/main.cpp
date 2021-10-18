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
    int ins{0};
    bool n0 = !(n%10);
    while(n) {
        if(!(n%100/10))
            ins = ins*10 + n%10;
        else
            ins = ins*100 + 10*(n%10) + ((n%10 > n%100/10) ? (n%10 - n%100/10) : (n%100/10 - n%10));
        n /= 10;
    }

    int res{0};
    while(ins) {
        res = res*10 + ins%10;
        ins /= 10;
    }
    n = res;
    if(n0) n *= 10;
}