#include <iostream>
#include <cstring>

using namespace std;

char x[50001], pare[1001][51], impare[1001][51], *p;
int n, m;

int main(){
    cin.getline(x, 50001);
    p = strtok(x, " ");
    while(p) {

        if(strlen(p)%2)
            strcpy(impare[++n], p);
        else
            strcpy(pare[++m], p);

        p = strtok(NULL, " ");
    }

    for(int i = 1; i <= n; ++i) {
        char tmp[51];
        int mijloc = strlen(impare[i])/2+1;

        strcpy(tmp, impare[i]);
        char aux[51];
        strcpy(aux, tmp+mijloc);
        tmp[mijloc] = tmp[mijloc-1];
        strcpy(tmp+mijloc+1, aux);
        
        for(int j = 1; j <= m; ++j)
            if(strcmp(tmp, pare[j]) == 0) { 
                cout << "DA";
                return 0;
            }
    }

    cout << "NU";
    return 0;
}