#include <fstream>
#include <cmath>

using namespace std;

ifstream fin ("elempp.in");
ofstream fout ("elempp.out");

int n, x, first2;

int main() {
    fin >> n;
    for(int i = 0; i < n; ++i) {
        fin >> x;

        first2 = x;
        while(first2 >= 100) {
            first2 /= 10;
        }

        if((double)sqrt(first2) == (int)sqrt(first2))
            fout << x << ' ';
    }
    return 0;
}