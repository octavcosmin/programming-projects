#include <stdio.h>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
vector<int> part;

int main() {
    freopen("media.in", "r", stdin);
    freopen("media.out", "w", stdout);

    scanf("%d%d", &N, &M);
    int Mpower{0};
    int cM = M;
    while(cM > 1) {
        ++Mpower;
        cM = cM >> 1;
    }

    int nrSecv{0};
    arr.push_back(0);
    part.push_back(0);
    for(int i = 1; i <= N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);

        int power{0};
        while(tmp > 1) {
            ++power;
            tmp = tmp >> 1;
        }
        
        if(i == 0)
            part.push_back(power);
        else
            part.push_back(part.back()+power);
        
        for(int j = 0; j < i; ++j) {
            if((part[i] - part[j]) == Mpower*(i-j))
                ++nrSecv;
        }
    }

    // for(int i = 1; i <= N; ++i)
    //     for(int j = 0; j < i; ++j)
    //         if((part[i] - part[j]) == Mpower*(i-j))
    //             ++nrSecv;
    printf("%d", nrSecv);
    return 0;
}