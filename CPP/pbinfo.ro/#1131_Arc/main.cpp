#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("arc.in");
ofstream fout("arc.out");

int main()
{
    int n,t;
    fin >> t >> n;
    int v[10005], contor = 1, contorN = n;
    struct{
        int lungime, valoare;
    }secventa[10005];
    for(int i = 1; i <= n; i++)
    {
        fin >> v[i];
    }
    secventa[1].lungime = 1;
    secventa[1].valoare = v[1];
    int secvMax = -1;
    for(int i = 2; i <= n; i++)
    {
        while(v[i] == v[i-1] && i <= n)
        {
            secventa[contor].lungime++;
            i++;
            if(secventa[contor].lungime > secvMax)
                secvMax = secventa[contor].lungime;
        }
        if(v[i] != v[i-1] && i != n+1)
        {
            contor++;
            secventa[contor].lungime = 1;
            secventa[contor].valoare = v[i];
        }
    }
    if(t == 1)
    {
        fout << contor;
        return 0;
    }
    while(secvMax >= 3)
    {
        for(int i = 1; i <= contor; i++)
        {
            if(secventa[i].lungime == secvMax)
            {
                for(int x = i+1; x <= contor; x++)
                    secventa[x-1] = secventa[x];
                contor--;
                contorN -= secvMax;
                while( i && secventa[i-1].valoare == secventa[i].valoare)
                {
                    secventa[i-1].lungime += secventa[i].lungime;
                    for(int x = i+1; x <= contor; x++)
                        secventa[x-1] = secventa[x];
                    contor--;
                    if(secventa[i-1].lungime >= 3)
                    {
                        contorN -= secventa[i-1].lungime;
                        for(int x = i; x <= contor; x++)
                            secventa[x-1] = secventa[x];
                            i -- ;
                        contor --;
                    }
                }
                break;
            }
        }
        secvMax = -1;
        for(int i = 1; i<= contor; i++)
        {
            if(secventa[i].lungime >= secvMax)
                secvMax = secventa[i].lungime;
        }
    }
    if(t == 2)
    {
        fout << contorN <<'\n';
        for(int i = 1; i <= contor; i++)
        {
            for(int j = 1; j <= secventa[i].lungime; j++)
                fout << secventa[i].valoare << '\n';
        }
    }
    return 0;
}
