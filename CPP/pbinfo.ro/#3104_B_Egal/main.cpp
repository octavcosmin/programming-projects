#include <iostream>
using namespace std;
bool Egal(int n);

int main() {
    int n;
    cin >> n;
    cout << Egal(n);
    return 0;
}

bool Egal(int n) {
    int val{-1};
    while(n) {
        if(n%10%2)
            if(val == -1)
                val = n%10;
            else if(n%10 != val)
                return 0;
        n /= 10;
    }
    return 1;
}