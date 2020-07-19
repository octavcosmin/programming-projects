#include <bits/stdc++.h>

using namespace std;

int cerinta;
vector<string> fete;

bool sortASCII(char x, char y) {
    return (int)x < (int)y;
}

string nume_de_baza(string nume) {
    vector<char> v;
    for(int i = 0; i < nume.length(); ++i)
        v.push_back(nume[i]);
    sort(v.begin(), v.end(), sortASCII);
    string sol(v.begin(), v.end());
    return sol;
}

vector<char> to_vector(string str) {
    vector<char> sol;
    for(int i = 0; i < str.length(); ++i)
        sol.push_back(str[i]);
    return sol;
}

string to_string(vector<char> v) {
    string sol;
    for(auto it = v.begin(); it != v.end(); ++it)
        sol += *it;
    return sol;
}

int main()
{
    freopen("raganama.in", "r", stdin);
    freopen("raganama.out", "w", stdout);

    scanf("%d", &cerinta);

    string nume;
    cin >> nume;
    fete.push_back(nume);

    vector<char> init = to_vector(nume_de_baza(nume));

    while(cin >> nume)
        fete.push_back(nume);

    sort(fete.begin(), fete.end());

    /*for(int i = 0; i < fete.size(); ++i)
        cout << fete[i] << '\n';*/

    int nrfrum = 0;
    int i = 0;
    do{
        string temp = to_string(init);
        while(temp > fete[i] && i < fete.size()-1)
            ++i;
        if(temp != fete[i]) {
            if(cerinta == 1) {
                cout << temp;
                return 0;
            }
            else {
                ++nrfrum;
                //fete.push_back(temp);
            }
        }
    }while(next_permutation(init.begin(), init.end()));

    if(cerinta == 2)
        printf("%d", nrfrum);
    else
        printf("-1");
    return 0;
}
