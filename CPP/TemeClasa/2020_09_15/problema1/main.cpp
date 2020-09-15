#include<stdio.h>
#include<math.h>

int main() {
    int a, b, suma{0};
    scanf("%d%d", &a, &b);
    
    while (a && b) {
        if (a%10 == b%10)
            suma += a%10;
        a /= 10;
        b /= 10;
    }

    printf("%d", suma);
    
    return 0;
}