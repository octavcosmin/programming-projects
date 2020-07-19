#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    short int n;
    cin >> n;
    long long S = 0;
    for(int i = 1; i <= n; i++)
        S += pow(i,i);
    cout << "Rezultatul este " << S;
    return 0;
}
