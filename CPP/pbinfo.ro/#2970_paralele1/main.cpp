#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

FILE* input = fopen("paralele.in","r");
FILE* output = fopen("paralele.out","w");

struct myMatrix {
    bool cell[40005][505];
    long long numberOfSegments[40005];
};
myMatrix matrix;

void readMatrix1(int x, int y);
void readMatrix2(int x, int y);
int countConsecutive(int x, int y, int consecutive);
long long totalSegmentsBelow(int startingAt, int lines);

int main()
{
    int T,n,m;
    fscanf(input,"%d %d %d", &T, &n, &m);
    T == 1 ? readMatrix1(n,m) : readMatrix2(n,m);
    if(T == 2) swap(n,m);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m+1; j++)
            if(matrix.cell[i][j] == 0)
                matrix.numberOfSegments[i] += countConsecutive(i,j,0);

    /*for(int i = 1; i <= m; i++)
        printf("%lld ", matrix.numberOfSegments[i]);*/
    /*for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            printf("%d ",matrix.cell[i][j]);
        printf("\n");
    }*/

    long long numberOfGroups = 0;
    int lines = n;
    for(int i = 1; i <= lines; i++)
        numberOfGroups += matrix.numberOfSegments[i]*totalSegmentsBelow(i+1,lines);

    fprintf(output,"%lld",numberOfGroups);
    return 0;
}

void readMatrix1(int x, int y)
{
    short temp;
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
        {
            fscanf(input,"%hd",&temp);
            matrix.cell[i][j]=temp;
        }
}
void readMatrix2(int x, int y)
{
    short temp;
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
        {
            fscanf(input,"%hd",&temp);
            matrix.cell[j][i]=temp;
        }
}
int countConsecutive(int x, int y, int consecutive)
{
    if(matrix.cell[x][y-1])
        return countConsecutive(x,y-1,consecutive+1);
    return consecutive*(consecutive-1)/2;
}
long long totalSegmentsBelow(int startingAt,int numberOfLines)
{
    long long numberOfSegmentsBelow = 0;
    for(int i = startingAt; i <= numberOfLines; i++)
        numberOfSegmentsBelow += matrix.numberOfSegments[i];
    return numberOfSegmentsBelow;
}
