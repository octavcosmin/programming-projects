#include <fstream>

using namespace std;
ifstream fin("cifreord1.in");
ofstream fout("cifreord1.out");

int fr[10];

int main() {
    char x;
    while(fin >> x) {
        if(x == ' ') continue;
        ++fr[x - '0'];
    }

    int out{0};
    for(int c = 9; c >= 0; --c) {
        while(fr[c]--) {
            if(out %20 == 0 && out != 0)
                fout << '\n';
            fout << c << ' ';
            ++out;
        }
    }
    return 0;
}