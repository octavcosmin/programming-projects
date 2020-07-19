#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char cifre[11];
    cin.getline(cifre, 11);
    short int cifraMax = 0, aparitii = 0;
    for(int i = 0; i < strlen(cifre); i++)
    {
        if(cifre[i] - '0' > cifraMax)
        {
            cifraMax = cifre[i] - '0';
            aparitii = 1;
            continue;
        }
        if(cifre[i] - '0' == cifraMax)
            aparitii++;
    }
    cout << cifraMax << ' ' << aparitii;
    return 0;
}
