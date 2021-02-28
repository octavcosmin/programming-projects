#include <vector>
#include <algorithm>

using namespace std;

class LargeNumber {
    public:
        vector<short> digit;
        friend LargeNumber operator >> (istream &in, LargeNumber &x);
        friend ostream &operator << (ostream &out, LargeNumber x);

        LargeNumber operator + (const LargeNumber& x) {
            LargeNumber sol;
            bool carry{false};

            auto it1 = x.digit.end() -1;
            auto it2 = this->digit.end() -1;

            for(; it1 != x.digit.begin() -1 && it2 != this->digit.begin() -1; --it1, --it2) {
                short tmp = *it1 + *it2 + carry;
                carry = false;
                if(tmp > 9) {
                    carry = true;
                    tmp -= 10;
                }

                sol.digit.push_back(tmp);
            }

            for(; it1 != x.digit.begin() -1; --it1) {
                short tmp = *it1 + carry;
                carry = false;
                if(tmp > 9) {
                    carry = true;
                    tmp -= 10;
                }

                sol.digit.push_back(tmp);
            }

            for(; it2 != this->digit.begin() -1; --it2) {
                short tmp = *it2 + carry;
                carry = false;
                if(tmp > 9) {
                    carry = true;
                    tmp -= 10;
                }

                sol.digit.push_back(tmp);
            }

            reverse(sol.digit.begin(), sol.digit.end());
            return sol;
        }
};

LargeNumber operator >> (istream &in, LargeNumber &x) {
    string tmp;
    in >> tmp;
    for(string::iterator it = tmp.begin(); it != tmp.end(); ++it)
        x.digit.push_back(*it - '0');
    return x;
}

ostream &operator << (ostream &out, LargeNumber x) {
    for(vector<short>::iterator it = x.digit.begin(); it != x.digit.end(); ++it)
        out << *it;
    return out;
}