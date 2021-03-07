#include <cstdio>

using namespace std;

int N, frec[1000];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int tmp;
        scanf("%d", &tmp);

        if(tmp < 1000)
            ++frec[tmp];
    }

    int found1{0}, found2{0};
    for(int i = 999; i > 99; --i) {
        if(found1 && found2)
            break;

        if(!frec[i]) {
            if(found2 == 0)
                found2 = i;
            else
                found1 = i;
        }
    }

    if(found1 && found2)
        printf("%d %d", found1, found2);
    else
        printf("NU EXISTA");
    return 0;
}