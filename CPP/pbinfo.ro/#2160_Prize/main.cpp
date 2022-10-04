#include <fstream>
using namespace std;
ifstream fin("prize.in");
ofstream fout("prize.out");
int n;
int main() {
    fin >> n;
    long long sum = 0;
    int x;
    for(int i = 1; i <= n; ++i) {
        fin >> x;
        sum += x;
    }
    sum -= n-1;
    fout << sum;
    return 0;
}