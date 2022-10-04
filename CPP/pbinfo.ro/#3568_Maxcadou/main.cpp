#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("maxcadou.in");
ofstream fout("maxcadou.out");
string nr;
int fr[10];
int main() {
    fin >> nr;
    for(string::iterator it = nr.begin(); it != nr.end(); ++it)
        ++fr[*it - '0'];
    for(int i = 9; i >= 0; --i)
        while(fr[i] > 0) {
            fout << i;
            --fr[i];
        }
    return 0;
}