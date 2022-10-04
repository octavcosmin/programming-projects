#include <bits/stdc++.h>

using namespace std;

bool check_munte(int a) {
    int c, sectiuni{};
    c = a%10, a/= 10;

    while(a && a%10 > c) {
        sectiuni = 1;
        c = a%10;
        a /= 10;
    }
    if(sectiuni != 1)
        return 0;
        
    while(a && a%10 < c) {
        sectiuni = 2;
        c = a%10;
        a /= 10;
    }

    return (sectiuni == 2);
}

int main() {
    int n;
    cin >> n;

    int x;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        cout << check_munte(x) << '\n';
    }
    return 0;
}