#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct hex_number {
    bool fr[17];
    int count;
};

string tmp;
hex_number current_number;
vector<hex_number> v;
int perechi;


int main() {

    freopen("perechi.in", "r", stdin);
    freopen("perechi.out", "w", stdout);

    while(cin >> tmp) {

        current_number.count = 0;
        memset(current_number.fr, 0, sizeof(current_number.fr));

        for(int i = 0; i < tmp.length(); ++i) {
            if('0' <= tmp[i] && tmp[i] <= '9')
                current_number.fr[tmp[i] - '0'] = true;
            else 
                if('A' <= tmp[i] && tmp[i] <= 'F')
                    current_number.fr[tmp[i] - 'A' + 10] = true;
                else {
                    cout << "Error: Invalid character detected!";
                    return -1;
                }
        }

        for(int i = 0; i < 16; ++i)
            current_number.count += current_number.fr[i];

        v.push_back(current_number);
    }

    for(int i = 0; i < v.size()-1; ++i) {
        for(int j = i+1; j < v.size(); ++j) {

            if(v[i].count + v[j].count != 16)
                break;
            
            for(int check = 0; check < 16; ++check) {
                if( !(v[i].fr[check]^v[j].fr[check]) )
                    break;
            }

            ++perechi;

        }
    }

    cout << perechi;
    return 0;
}