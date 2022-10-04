#include <iostream>
using namespace std;
int n, k, x, sum;
int main(){
    cin >> n >> k;
    for(int i = 0; i < k; ++i) {
        cin >> x;
        sum += x;
    }
    cout << (sum == 0 ? "DA" : "NU");
    return 0;
}