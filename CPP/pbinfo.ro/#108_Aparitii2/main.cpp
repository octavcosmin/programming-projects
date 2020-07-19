#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char numar[11];
    cin.getline(numar,11);
    int aparitii = 0, ultimaCifra = numar[0] - '0';
    for(int i = 0; i < strlen(numar); i++)
        aparitii += (ultimaCifra == numar[i] - '0') ? 1 : 0;
    cout << aparitii;
    return 0;
}
