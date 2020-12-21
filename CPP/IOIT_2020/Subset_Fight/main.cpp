#include <iostream>
#define NMAX 50
using namespace std;
int n,i,s,contor,cn;
int nr[NMAX];
int p[NMAX];
int uz[NMAX];
void gen(int k,int nr[]);
void nrbune();
int main()
{
cin>>n; cn=n;
for (i=1;i<=n;i++)
    {cin>>nr[i];
     s+=nr[i];
    }
n=s;
gen(1,nr);
cout<<contor<<'\n';
return 0;
    return 0;
}
void gen(int k,int nr[])
///cand apelez gen(k) poz 1,2,...,k-1 din p sunt deja ocupate
{int i,j;
if (k-1==n) nrbune();
else ///sol nu e completa
///ocup poz k;
for (i=1;i<=n;i++)
///verific daca valoarea i a fost deja folosita
    {
     if (uz[i]<nr[i]) ///i nu a fost deja folosit
        {p[k]=i; uz[i]++;
         gen(k+1,nr);
         uz[i]--;
        }
    }
}
void nrbune()
{int i,suma;
for (i=1;i<=n;i++)
    {suma+=p[i];
     if (suma%cn==0)
        contor++;
     contor=contor%1000000007;
    }
}