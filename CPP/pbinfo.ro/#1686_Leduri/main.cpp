#include <bits/stdc++.h>

using namespace std;
FILE *in, *out;

int n, poz, nrapasari;
vector<bool> init, fin, s1, s2;

void citire() {
    in = fopen("leduri.in","r");
    fscanf(in,"%d", &n);
    for(int i = 0; i < n; ++i) {
        int temp;
        fscanf(in,"%d", &temp);
        init.push_back(temp);
    }
    for(int i = 0; i < n; ++i) {
        int temp;
        fscanf(in,"%d", &temp);
        fin.push_back(temp);
    }
    fclose(in);
}

void marcare_corecte(vector<bool> &cablu) {
    while(cablu[poz] == fin[poz] && poz < n)
        ++poz;
}

bool apasare(vector<bool> &cablu, int pozitie) {
    ++nrapasari;
    if(pozitie == 0) {
        cablu[pozitie] = !cablu[pozitie];
        cablu[pozitie+1] = !cablu[pozitie+1];
        //cout << cablu[pozitie] << ' ' << cablu[pozitie+1] << '\n';
        return 0;
    }
    if(pozitie == cablu.size()-1) {
        cablu[pozitie] = !cablu[pozitie];
        cablu[pozitie-1] = !cablu[pozitie-1];
        //cout << cablu[pozitie-1] << ' ' << cablu[pozitie] << '\n';
        return 0;
    }
    cablu[pozitie] = !cablu[pozitie];
    cablu[pozitie+1] = !cablu[pozitie+1];
    cablu[pozitie-1] = !cablu[pozitie-1];
    //cout << cablu[pozitie-1] << ' ' << cablu[pozitie] << cablu[pozitie+1] << '\n';
    /*for(int i = 0; i < n; ++i)
        cout << cablu[i] << ' ';
    cout << '\n';*/
    return 0;
}

/*void afisare_test(vector<bool> &v) {
    for(int i = 0; i < n; ++i)
        cout << v[i] << ' ';
    cout << '\n';
}*/

int main()
{
    citire();
    marcare_corecte(init);
    if(poz == 0) {
        s1 = init;
        apasare(s1, 0);

        s2 = init;
        //apasare(s2, 1);

        nrapasari = 1;
        while(poz < n-1) {
            marcare_corecte(s1);
            apasare(s1, poz+1);
        }
        int nra1 = nrapasari;

        nrapasari = 1;
        poz = 0;
        while(poz < n-1) {
            marcare_corecte(s2);
            apasare(s2, poz+1);
        }
        nrapasari = min(nrapasari, nra1);
    }
    else{
        nrapasari = 0;
        while(poz < n-1) {
            marcare_corecte(init);
            apasare(init, poz+1);
        }
    }

    out = fopen("leduri.out","w");
    fprintf(out,"%d", nrapasari);
    fclose(out);
    return 0;
}
