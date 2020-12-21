/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// input data
int N;
long long cost, cost2, cost3, cost4;
vector<int> H, H2, H3, H4;

long long sqr(int a) {return a*a;}

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
    H2.resize(N);
    H3.resize(N);
    H4.resize(N);
    for (int i=0; i<N; i++) {
        cin >> H[i];
        H2[i] = H[i];
        H3[i] = H[i];
        H4[i] = H[i];
        if(i == 1) {
            if(H[0] == H[1]) {
                ++H[1];
                ++cost;
                ++H2[0];
                ++cost2;
            }
            else {
                cost2 += sqr(abs(H2[0]-(H2[1]+H2[0])/2)) + sqr(abs(H[1]-(H2[1]+H2[0])/2)+1);
                H2[0] = (H2[1]+H2[0])/2;
                H2[1] = H2[0]+1;
            }
        }
        if(i >= 2 /*&& i < N-2*/) {
            if(H[i-2] < H[i-1] && H[i-1] <= H[i]) {
                cost += sqr(H[i] - H[i-1] +1);
                H[i] = H[i-1]-1;
            }
            else{
                if(H[i-2] > H[i-1] && H[i-1] >= H[i]) {
                    cost += sqr(H[i-1] - H[i] +1);
                    H[i] = H[i-1]+1;
                }
            }

            if(H2[i-2] < H2[i-1] && H2[i-1] <= H2[i]) {
                cost2 += sqr(H2[i] - H2[i-1] +1);
                H2[i] = H2[i-1]-1;
            }
            else{
                if(H2[i-2] > H2[i-1] && H2[i-1] >= H2[i]) {
                    cost2 += sqr(H2[i-1] - H2[i] +1);
                    H2[i] = H2[i-1]+1;
                }
            }
        }
    }

    reverse(H3.begin(), H3.end());
    reverse(H4.begin(), H4.end());

    for(int i = 0; i < N; ++i) {
        if(i == 1) {
            if(H3[0] == H4[1]) {
                ++H3[1];
                ++cost3;
                ++H4[0];
                ++cost4;
            }
            else {
                cost4 += sqr(abs(H4[0]-(H4[1]+H4[0])/2)) + sqr(abs(H3[1]-(H4[1]+H4[0])/2)+1);
                H4[0] = (H4[1]+H4[0])/2;
                H4[1] = H4[0]+1;
            }
        }
        if(i >= 2 /*&& i < N-2*/) {
            if(H3[i-2] < H3[i-1] && H3[i-1] <= H3[i]) {
                cost3 += sqr(H3[i] - H3[i-1] +1);
                H3[i] = H3[i-1]-1;
            }
            else{
                if(H3[i-2] > H3[i-1] && H3[i-1] >= H3[i]) {
                    cost3 += sqr(H3[i-1] - H3[i] +1);
                    H3[i] = H3[i-1]+1;
                }
            }

            if(H4[i-2] < H4[i-1] && H4[i-1] <= H4[i]) {
                cost4 += sqr(H4[i] - H4[i-1] +1);
                H4[i] = H4[i-1]-1;
            }
            else{
                if(H4[i-2] > H4[i-1] && H4[i-1] >= H4[i]) {
                    cost4 += sqr(H4[i-1] - H4[i] +1);
                    H4[i] = H4[i-1]+1;
                }
            }
        }
    }

    // insert your code here
    // for(auto it:H)
    //     cout<<it<<" ";
    // cout<<'\n';
    // for(auto it:H2)
    //     cout<<it<<" ";
    // cout<<'\n';
    // for(auto it:H3)
    //     cout<<it<<" ";
    // cout<<'\n';
    // for(auto it:H4)
    //     cout<<it<<" ";
    // cout<<'\n';

    cout << min(min(cost, cost2),min(cost3, cost4)) << endl; // print the result
    return 0;
}
