#include <cstdio>
#include <vector>

using namespace std;

int N, pozmax, valmax, minraise;
vector<int> H, raise;

FILE *in, *out;

int main() {
    //Read
    in = fopen("ascdesc.in", "r");
    fscanf(in, "%d", &N);
    for(int i = 0; i < N; ++i) {
        int tmp;
        fscanf(in, "%d", &tmp);
        H.push_back(tmp);

        //Finding max value
        if(tmp > valmax) {
            valmax = tmp;
            pozmax = i;
        }
    }
    fclose(in);

    //Set vector size
    raise.resize(N,0);

    for(int i = pozmax-1; i >= 0; --i) {
        //minraise: number of sections that need to be raised anyways
        if(H[i] < H[i-1]) {
            minraise += H[i-1] - H[i];
            H[i] = H[i-1];
        }

        //Partial sums from pozmax to begining
        raise[i] = raise[i+1] + (valmax - H[i]);
    }

    for(int i = pozmax+1; i < N; ++i) {
        //minraise: number of sections that need to be raised anyways
        if(H[i] < H[i+1]) {
            minraise += H[i+1] - H[i];
            H[i] = H[i+1];
        }

        //Partial sums from pozmax to end
        raise[i] = raise[i-1] + (valmax - H[i]);
    }

    //Write
    out = fopen("ascdesc.out", "w");
    for(int i = 0; i < N; ++i)
        fprintf(out, "%d ", raise[i] + minraise);
    fclose(out);
    return 0;
}