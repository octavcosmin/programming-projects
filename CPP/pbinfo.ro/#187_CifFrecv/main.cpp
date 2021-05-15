#include <fstream>

using namespace std;

ifstream fin("ciffrecv.in");
ofstream fout("ciffrecv.out");

int fr[10];

int main() {
    int x;
    while(fin >> x)
        ++fr[x];

    if(fr[7]) {
        fout << "7 " << fr[7];
        return 0;
    }
    if(fr[5]) {
        fout << "5 " << fr[5];
        return 0;
    }
    if(fr[3]) {
        fout << "3 " << fr[3];
        return 0;
    }
    fout << "2 " << fr[2];
    return 0;
}