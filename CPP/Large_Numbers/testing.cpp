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
    fout << "x's sign: " << x.sign << '\n';
    fout << "y: " << y << '\n';
    fout << "y's sign: " << y.sign << '\n';

    fout << "Sum: " << x + y << '\n';
    fout << "Difference: " << x - y << '\n';
    fout << "The other difference: " << y - x << '\n';
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

    fout << "String for x: " << x.toString() << '\n';
    fout << "String for y: " << y.toString() << '\n';

    LargeNumber m;
    m = -645747;
    fout << "Initialized with int (m): " << m << '\n';

    string str = "-96308763084656";
    LargeNumber n;
    n = str;
    fout << "Initialized with string (n): " << n << '\n';
    return 0;
}