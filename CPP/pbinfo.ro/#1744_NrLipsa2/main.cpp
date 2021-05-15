#include <fstream>

using namespace std;
ifstream fin("nrlipsa2.in");
ofstream fout("nrlipsa2.out");

int fr[205];

int main() {
    int x;
    while(fin >> x) {
        if(x >= -100 && x <= 100)
            ++fr[x+100];
    }

    int i = 0;
    while(i < 200) {
        ++i;
        if(fr[i] == 0) {
            fout << i-100;
            return 0;
        }
    }

    fout << "nu exista";
    return 0;
}