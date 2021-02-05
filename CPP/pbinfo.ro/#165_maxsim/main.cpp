#include <fstream>

using namespace std;

ifstream fin ("maxsim.in");
ofstream fout ("maxsim.out");

int n, v[1005], smax, imax, jmax;

int main() {
    fin >> n;
    
    for(int i = 1; i <= n; ++i) {
        fin >> v[i];

        if(i > n/2 && smax <= v[i] + v[n-i+1]) {
            smax = v[i] + v[n-i+1];
            imax = n-i+1;
            jmax = i;
        }
    }

    fout << smax << ' ' << imax << ' ' << jmax;
    return 0;
}