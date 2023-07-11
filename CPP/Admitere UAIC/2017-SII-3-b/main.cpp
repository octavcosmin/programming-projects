#include <iostream>
#include <cstring>

using namespace std;

int m, n;
char A[26];
string s[101];
bool letters[26];

int sameLetters(string a, string b) {
    int freq_a[26] = {}, freq_b[26] = {};
    for(int i = 0; i < max(a.size(), b.size()); ++i) {
        if(i < a.size()) ++freq_a[a[i] - 'a'];
        if(i < b.size()) ++freq_b[b[i] - 'a'];
    }

    int count = 0;
    for(int i = 0; i < 26; ++i)
        if(freq_a[i] == 1 && freq_b[i] == 1) ++count;
    return count;
}

void checkLetters(string s) {
    for(int i = 0; i < s.size(); ++i)
        letters[s[i] - 'a'] = 1;
}

int main() {
    // Cerinta b1
    cin >> m;
    for(int i = 0; i < m; ++i) A[i] = (char)('a'+i);

    // Cerinta b2
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> s[i];

    //Cerinta b3
    int p = s[0].size();
    checkLetters(s[n-1]);
    for(int i = 0; i < n-1; ++i) {
        checkLetters(s[i]);
        for(int j = i+1; j < n; ++j)
            if(s[j].size() != p || sameLetters(s[i], s[j]) != 1) {
                cout << "NU";
                return 0;
            }
    }
    for(int i = 0; i < m; ++i)
        if(!letters[i]) {
            cout << "NU";
            return 0;
        }
    cout << "DA";
    return 0;
}

/*EXAMPLE
6
3
abc cde adf
*/