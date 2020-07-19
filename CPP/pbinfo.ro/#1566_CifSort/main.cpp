#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char numar[9];
    cin.getline(numar,9);
    for(int i = 0; i < strlen(numar); i++)
        cout << numar[(i % 2 == 0) ? i+1 : i-1];
    return 0;
}
