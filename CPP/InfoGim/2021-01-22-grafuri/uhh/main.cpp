#include <cstdio>
#include <queue>

using namespace std;
 
const int NMAX = 200001;

struct Muchie{
    int x,y;
    int cost;
    friend bool operator > (const Muchie&, const Muchie&);
};

bool operator > (const Muchie& m1, const Muchie& m2){
    return m1.cost>m2.cost;
}
 
priority_queue <Muchie, vector<Muchie>, greater<Muchie> > H;
vector<Muchie> sol;
 
int t[NMAX], l[NMAX], n,nr,costmin;
 
void Citire();
 
int fnd(int x){
	int r,y;
	r=x;
	while(t[r]!=r)
        r=t[r];
    y=x;
    int tata;
	while(y!=r)
	{
		tata=t[y];
		t[y]=r;
		y=tata;
	}
	return r;
}
void unire(int x, int y){
	if (l[x]>l[y])
		t[y]=x;
    else
        t[x]=y;
	if (l[x]==l[y])
        l[y]++;
}
 
 
int main(){
    int c1,c2;
    freopen("apm.in", "r", stdin);
    scanf("%d%d", &n, &nr);
    for(int i=1;i<=n;i++)
        t[i]=i;
    Muchie m;
    for(int i=1;i<=nr;i++)
    {
        scanf("%d%d%d", &m.x, &m.y, &m.cost);
        H.push(m);
    }
    while(sol.size()<n-1) //cat timp nu am selectat cele n-1 muchii
    {
        //extrag din H muchia de cost minim
        m=H.top(); H.pop();
        //determin comp conexe din care fac parte
        //extremitatile muchiei selectate m
        c1=fnd(m.x); c2=fnd(m.y);
        if(c1!=c2) //m nu formeaza cicluri cu muchiile selectate
        {
            //selectez aceasta muchie
            costmin+=m.cost; sol.push_back(m);
            //unific componentele conexe ale extremitatilor
            unire(c1,c2);
        }
    }

    freopen("apm.out", "w", stdout);

    printf("%d\n%d\n", costmin, sol.size());
    for(int i=0;i<sol.size();i++)
        printf("%d %d\n", sol[i].y, sol[i].x);
    return 0;
}