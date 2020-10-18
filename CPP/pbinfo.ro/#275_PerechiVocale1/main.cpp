#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>

FILE *in, *out;

char x, lastx;
std::map<std::string,int> freq;

bool isVowel(char c) {
    if(c == 'a'
    || c == 'e'
    || c == 'i'
    || c == 'o'
    || c == 'u')
       return true;
    return false;
}

int main() {

    in = fopen("perechivocale1.in", "r");

    while(fscanf(in, "%c", &x)) {
        if(isVowel(x) && isVowel(lastx)) {
            
        }
    }
    return 0;
}