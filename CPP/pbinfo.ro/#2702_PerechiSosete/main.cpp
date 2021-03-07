#include <cstdio>

using namespace std;

int N, frec[101], nrperechi;

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ++frec[tmp];
    }

    for(int i = 0; i < 101; ++i)
        nrperechi += frec[i]/2;
    
    printf("%d", nrperechi);
    return 0;
}