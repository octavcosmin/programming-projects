#include <fstream>
#include "LargeNumbers.h"

using namespace std;

ifstream fin("testing.in");
ofstream fout("testing.out");

LargeNumber x, y;

int main() {
    fin >> x;
    fin >> y;

    fout << "x: " << x << '\n';
    fout << "y: " << y << '\n';

    fout << "Sum: " << x + y << '\n';
    fout << "Difference (abs): " << (x >= y ? x - y : y - x) << '\n';

    fout << "x > y: ";
    if(x > y) fout << "true" << '\n';
    else fout << "false" << '\n';

    fout << "x >= y: ";
    if(x >= y) fout << "true" << '\n';
    else fout << "false" << '\n';
    
    fout << "x < y: ";
    if(x < y) fout << "true" << '\n';
    else fout << "false" << '\n';

    fout << "x <= y: ";
    if(x <= y) fout << "true" << '\n';
    else fout << "false" << '\n';

    fout << "x == y: ";
    if(x == y) fout << "true" << '\n';
    else fout << "false" << '\n';
        
    fout << "x != y: ";
    if(x != y) fout << "true" << '\n';
    else fout << "false" << '\n';
    return 0;
}