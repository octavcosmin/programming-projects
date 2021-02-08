#include <fstream>
#include <cmath>
#include <algorithm>

#include <iostream>

using namespace std;

ifstream fin("sortare_divizori.in");
ofstream fout("sortare_divizori.out");

int n;
pair<int,int> v[1005];

bool by_divisors(pair<int,int> a, pair<int,int> b) {
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int count_divisors(int x) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(x); i++) { 
        if (x % i == 0) { 
            if (x / i == i) 
                cnt++; 
            else
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

int main() {
    fin >> n;
    for(int i = 1; i <= n; ++i) {
        fin >> v[i].first;
        v[i].second = count_divisors(v[i].first);
    }

    sort(v+1, v+1+n, by_divisors);

    for(int i = 1; i <= n; ++i) 
        fout << v[i].first << ' ';
    return 0;
}