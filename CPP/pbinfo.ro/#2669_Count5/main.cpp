#include <iostream>

using namespace std;

int fr_sum[100];
unsigned long long result;

unsigned long long C(int k, int n);

int main() {

    string x;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        int sum{0};

        for(int c = 0; c < x.size(); ++c)
            sum += x[c] - '0';
        
        ++fr_sum[sum];
    }

    for(int i = 0; i < 100; ++i)
        if(fr_sum[i] > 1)
            result += C(2, fr_sum[i]);

    cout << result;
    return 0;
}

unsigned long long C(int k, int n) {
    if(k == 1) return n;
    if(n == k) return 1;
    return C(k-1, n-1) + C(k, n-1);
}