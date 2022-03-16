#include <cstdio>
#include <map>
 
using namespace std;
 
int tata[10005];
map<int,int> mapare;
 
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
{   int n, i, x, y, tip;
    freopen("entries.in", "r",stdin);
    scanf("%d%d", &n);
    for(i=1; i<=10005; i++)
        tata[i]=i;
    freopen("entries.out", "w", stdout);
    for(i=1; i<=n; i++)
    {
        scanf("%d%d%d", &x, &y, &tip);
        mapare[]
        if(tip==1)
            unire(x, y);
        else
        {
            int s1=sef(x);
            int s2=sef(y);
            if(s1==s2)
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}