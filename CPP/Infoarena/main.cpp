#include <cstdio>
 
using namespace std;
 
int tata[100005];
 
int sef(int x)
{
    if(tata[x]==x)
        return x;
    else
        return tata[x]=sef(tata[x]);
 
}
void unire(int x, int y)
{
    int s1=sef(x);
    int s2=sef(y);
    tata[s2]=s1;
}
int main()
{   int n, m, i, ii, x, y, tip;
    freopen("disjoint.in", "r",stdin);
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++)
        tata[i]=i;
    freopen("disjoint.out", "w", stdout);
    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d", &tip, &x, &y);
        if(tip==1)
            unire(x, y);
        else
        {
            int s1=sef(x);
            int s2=sef(y);
            if(s1==s2)
                printf("DA\n");
            else
                printf("NU\n");
        }
    }
    return 0;
}