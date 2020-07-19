#include <iostream>

using namespace std;

long long a, b;
int max1, max2, min1, min2;

int main()
{
    cin >> a >> b;//Citire clar
    //descompunerea primului numar
    max1 = -1;
    min1 = 10;
    while(a) {
        if(max1 < a%10)
            max1 = a%10;
        if(min1 > a%10)
            min1 = a%10;
        a /= 10;
    }
    //descompunerea celui deal doilea numar
    max2 = -1;
    min2 = 10;
    while(b) {
        if(max2 < b%10)
            max2 = b%10;
        if(min2 > b%10 && ((min1 == 0 && b%10 != 0) || min1 != 0))
            min2 = b%10;
        b /= 10;
    }

    //afisare numar minim
    if(min1 <= min2 && min1 != 0)
        cout << min1 << min2 << ' ';
    else
        cout << min2 << min1 << ' ';

    //afisare numar maxim
    if(max1 >= max2 && max1 != 0)
        cout << max1 << max2 << ' ';
    else
        cout << max2 << max1 << ' ';
    return 0;
}
