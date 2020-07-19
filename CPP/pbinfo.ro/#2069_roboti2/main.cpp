#include <bits/stdc++.h>

using namespace std;

ifstream in("roboti2.in");
ofstream out("roboti2.out");

short int cerinta;
int n, lsir = 1, lsirMax;
bool sir, parcurs;
int roboti[100005];
deque<int> dq;

int aparitii(int x, int y){
int j, nr_puteri_identice=1;
//x pozitia in sir; y numarul din roboti d pe pozitia x  roboti[x]
for(int j = x; j <= n; ++j){
        while( roboti [ j ] == 1  ) {j++;} ;
        if (roboti [ j ] == roboti [ j+1 ]  ) {nr_puteri_identice++; j++;}
        }
return nr_puteri_identice;
}

void cerinta1()
{
    int i = 2, parcurgeri = 0;
        while(i <= n && parcurgeri <= 1)
        {
            if(roboti[i] > roboti[i-1])
                lsir++;
            else {
                lsirMax = max(lsir, lsirMax);
                lsir = 1;
            }
            i++;

            if(i == n+1)
            {
                if(roboti[1] > roboti[n])
                {
                    i = 2;
                    lsir++;
                }
                parcurgeri++;
            }
        }
        out << max(lsir, lsirMax);
}

void cerinta2()
{
    sort(roboti+1, roboti+n+1);
    int diferiti = 1;
    for(int i = 2; i <= n-1; ++i) {
            if ( roboti [ i ] == roboti [ n ] ) break ;
        if(roboti[i] != roboti[i-1] && roboti[i] != roboti[i+1])
            diferiti++;
    }

    dq.push_back(roboti[n]);
    for(int i = n-1; i >= 1; --i) {
        if(dq.front() == dq.back()) {
            if(diferiti % 2 == 1)
                dq.push_front(roboti[i]);
            else
                dq.push_back(roboti[i]);
        }
        else {
            if(dq.front() > dq.back())
                dq.push_front(roboti[i]);
            else
                dq.push_back(roboti[i]);
        }
    }

    int lungime = n;
    while(!dq.empty() && dq.front() == roboti[1]) {
        out << roboti[1] << ' ';
        dq.pop_front();
        --lungime;
    }
    while(!dq.empty() && dq.back() == roboti[1]) {
        out << roboti[1] << ' ';
        dq.pop_back();
        --lungime;
    }

    /*if(dq[1] == dq[lungime-2] && dq.front() < dq.back())
        swap(dq[0], dq[lungime-1]);
    for(int i = 2; i < lungime - 2; ++i) {
        for(int j = i+1; j < lungime - 1; ++j) {
            if(dq[i-1] == dq[j+1] && dq[i+1] == dq[j-1] && dq[i] < dq[j])
                swap(dq[i], dq[j]);
        }
    }*/

    while(!dq.empty()) {
        if(diferiti%2 == 1) {
            out << dq.front() << ' ';
            dq.pop_front();
        }
        else {
            out << dq.back() << ' ';
            dq.pop_back();
        }
    }
}
int main()
{
    in >> cerinta >> n;

    for(int i = 1; i <= n; i++)
        in >> roboti[i];
    if(cerinta == 1) {
        cerinta1();
        return 0;
    }
    cerinta2();
    return 0;
}
