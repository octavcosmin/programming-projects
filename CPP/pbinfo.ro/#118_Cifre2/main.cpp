#include <iostream>

using namespace std;

int main()
{
    char cifre[3];
    cin.getline(cifre, 3);
    cout << cifre[0] - '0' + cifre[1] - '0';
    return 0;
}
