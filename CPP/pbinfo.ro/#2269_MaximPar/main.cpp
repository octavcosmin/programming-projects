#include <bits/stdc++.h>

using namespace std;

FILE *inFile = fopen("maximpar.in", "r");
FILE *outFile = fopen("maximpar.out", "w");

int n, x, parMax = -1, aparitii;

int main()
{
    fscanf(inFile, "%d", &n);
    for(int i = 1; i <= n; ++i) {
        fscanf(inFile, "%d", &x);
        if(x%2 == 1)
            continue;
        if(x == parMax)
            ++aparitii;
        if(x > parMax)
            parMax = x, aparitii = 1;
    }
    if(parMax == -1)
        fprintf(outFile, "%d", parMax);
    else
        fprintf(outFile, "%d %d", parMax, aparitii);
    return 0;
}
