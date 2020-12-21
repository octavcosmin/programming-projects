#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

FILE *in, *out;
string nume;

int main() {
    in = fopen("test.in", "r");
    fscanf(in, "%s", &nume);
    fclose(in);

    out = fopen("test.out", "w");
    fprintf(out, "Hello %s", nume);
    fclose(out);
    return 0;
}