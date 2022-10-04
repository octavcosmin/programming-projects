#include <iostream>
using namespace std;

int n, vf, i, tmp;
struct {
    int l, index;
} st[1001];

int main() {
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> tmp;
        //CAZUL 1: primul cub
        //SI
        //CAZUL 2: cub mai mic (sau egal) decat varful
        if(i == 1 || tmp <= st[vf].l) {
            st[++vf].l = tmp;
            st[vf].index = i;
        }
        else { //CAZUL 3: cub mai mare decat varful
            while(tmp > st[vf].l && vf > 0)
                vf--;
            st[++vf].l = tmp;
            st[vf].index = i;
        }
    }
    
    cout << vf << '\n';
    for(i = 1; i <= vf; i++)
        cout << st[i].index << ' ';
    return 0;
}