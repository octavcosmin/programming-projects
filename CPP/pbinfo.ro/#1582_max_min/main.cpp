#include <bits/stdc++.h>

using namespace std;

int n;
string x;
int currentNumber;
int sumaCifre, sumMin = INT_MAX, nrSumMin, sumMax = INT_MIN, nrSumMax;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> x;
        currentNumber = 0;
        sumaCifre = 0;
        for(int c = 0; c < x.length(); ++c) {
            sumaCifre += x[c] - '0';
            currentNumber = currentNumber*10 + (x[c] - '0');
        }
        if(sumaCifre < sumMin) {
            sumMin = sumaCifre;
            nrSumMin = currentNumber;
        }
        if(sumaCifre > sumMax) {
            sumMax = sumaCifre;
            nrSumMax = currentNumber;
        }
    }
    cout << nrSumMin << '\n' << nrSumMax;
    return 0;
}
