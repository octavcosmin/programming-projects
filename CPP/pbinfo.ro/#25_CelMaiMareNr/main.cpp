#include <iostream>
using namespace std;
int cmmnr(int n);

int main() {
    int n;
    cin >> n;
    cout << cmmnr(n);
    return 0;
}

int cmmnr(int n) {
    int fr[10]{0,0,0,0,0,0,0,0,0,0};
    do{
        ++fr[n%10];
        n /= 10;
    }while(n);

    int res{0};
    for(int i = 9; i >= 0; --i)
        while(fr[i]--)
            res = res*10 + i;
    return res;
}