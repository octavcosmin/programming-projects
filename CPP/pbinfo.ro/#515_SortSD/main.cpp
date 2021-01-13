#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct div_array{
    int el, sum;
};

int div_sum(int num) 
{ 
    int result = 0;
    for (int d=2; d<=sqrt(num); d++)
    {
        if (num % d==0)
        {
            if (d == (num/d)) 
                result += d;
            else
                result += (d + num/d);
        }
    }
    return (result + 1 + num);
} 

bool by_div_sum(div_array a, div_array b) {
    if(a.sum != b.sum) return a.sum < b.sum;
    else return a.el < b.el;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<div_array> arr;
    for(int i = 0; i < n; ++i) {
        div_array tmp;
        scanf("%d", &tmp.el);
        tmp.sum = div_sum(tmp.el);

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), by_div_sum);

    for(auto it = arr.begin(); it != arr.end(); ++it)
        printf("%d ", it->el);
    return 0;
}