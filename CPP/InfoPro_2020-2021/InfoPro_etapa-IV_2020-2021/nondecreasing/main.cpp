#include <cstdio>
#include <vector>

using namespace std;

FILE *in, *out;

vector<int> arr;

int main() {
    in = fopen("nondecreasing.in", "r");
    char tmp;
    while(fscanf(in, "%c", &tmp) == 1)
        arr.push_back(tmp - 'a' +1);

    
    return 0;
}