#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class LargeNumber {
    public:
        vector<short> digit;
        bool sign{1};

        friend LargeNumber operator >> (istream &in, LargeNumber &x);
        friend ostream &operator << (ostream &out, LargeNumber x);

        friend bool operator == (const LargeNumber& x1, const LargeNumber& x2);
        friend bool operator != (const LargeNumber& x1, const LargeNumber& x2);
        friend bool operator > (const LargeNumber& x1, const LargeNumber& x2);
        friend bool operator >= (const LargeNumber& x1, const LargeNumber& x2);
        friend bool operator < (const LargeNumber& x1, const LargeNumber& x2);
        friend bool operator <= (const LargeNumber& x1, const LargeNumber& x2);


        LargeNumber operator + (const LargeNumber& x) {

            //Cazuri speciale pentru semne

            //* Cazul (+,-) si (-,+)
            if(this->sign != x.sign) {
                LargeNumber tmp, tmp2;
                tmp.digit = this->digit;
                tmp.sign = 1;
                tmp2.digit = x.digit;
                tmp2.sign = 1;
                return tmp - tmp2;
            }

            LargeNumber sol;
            bool carry{false};

            if(!this->sign && !x.sign)
                sol.sign = 0;

            auto it1 = this->digit.end() -1;
            auto it2 = x.digit.end() -1;

            for(; it1 != this->digit.begin() -1 && it2 != x.digit.begin() -1; --it1, --it2) {
                short tmp = *it1 + *it2 + carry;
                carry = false;
                if(tmp > 9) {
                    carry = true;
                    tmp -= 10;
                }

                sol.digit.push_back(tmp);
            }

            for(; it1 != this->digit.begin() -1; --it1) {
                short tmp = *it1 + carry;
                carry = false;
                if(tmp > 9) {
                    carry = true;
                    tmp -= 10;
                }

                sol.digit.push_back(tmp);
            }

            for(; it2 != x.digit.begin() -1; --it2) {
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

        LargeNumber operator - (const LargeNumber& x) {

            //Cazuri speciale pentru semne

            //* Cazul + si -
            if(this->sign == 1 && x.sign == 0) {
                LargeNumber tmp, tmp2;
                tmp.digit = this->digit;
                tmp.sign = 1;
                tmp2.digit = x.digit;
                tmp2.sign = 1;
                return tmp + tmp2;
            }

            //* Cazul - si +
            if(this->sign == 0 && x.sign == 1) {
                LargeNumber tmp, tmp2;
                tmp.digit = this->digit;
                tmp.sign = 1;
                tmp2.digit = x.digit;
                tmp2.sign = 1;
                LargeNumber reverseTmp = tmp + tmp2;
                reverseTmp.sign = reverseTmp.sign ? 0 : 1;
                return reverseTmp;
            }

            //* Cazul - si -
            if(this->sign == 0 && x.sign == 0) {
                LargeNumber tmp, tmp2;
                tmp.digit = this->digit;
                tmp.sign = 1;
                tmp2.digit = x.digit;
                tmp2.sign = 1;
                return tmp2 - tmp;
            }


            LargeNumber sol;
            bool take{false};

            auto it1 = this->digit.end() -1;
            auto it2 = x.digit.end() -1;

            //Cazul primul termen mai MARE decat al doilea
            if(*this >= x) {
                    
                for(; it1 != this->digit.begin() -1 && it2 != x.digit.begin() -1; --it1, --it2) {
                    short tmp = *it1 - *it2 - take;
                    take = false;
                    if(tmp < 0) {
                        take = true;
                        tmp += 10;
                    }

                    sol.digit.push_back(tmp);
                }

                for(; it1 != this->digit.begin() -1; --it1) {
                    short tmp = *it1 - take;
                    take = false;
                    if(tmp < 0) {
                        take = true;
                        tmp += 10;
                    }

                    sol.digit.push_back(tmp);
                }

                for(; it2 != x.digit.begin() -1; --it2) {
                    short tmp = *it2 - take;
                    take = false;
                    if(tmp < 0) {
                        take = true;
                        tmp += 10;
                    }

                    sol.digit.push_back(tmp);
                }

                if(take)
                    sol.sign = 0;
                    
            }
            
            //Cazul primul termen mai MIC decat al doilea
            else {
                    
                for(; it1 != this->digit.begin() -1 && it2 != x.digit.begin() -1; --it1, --it2) {
                    short tmp = *it2 - *it1 - take;
                    take = false;
                    if(tmp < 0) {
                        take = true;
                        tmp += 10;
                    }

                    sol.digit.push_back(tmp);
                }

                for(; it1 != this->digit.begin() -1; --it1) {
                    short tmp = *it1 - take;
                    take = false;
                    if(tmp < 0) {
                        take = true;
                        tmp += 10;
                    }

                    sol.digit.push_back(tmp);
                }

                for(; it2 != x.digit.begin() -1; --it2) {
                    short tmp = *it2 - take;
                    take = false;
                    if(tmp < 0) {
                        take = true;
                        tmp += 10;
                    }

                    sol.digit.push_back(tmp);
                }

                if(!take)
                    sol.sign = 0;

            }

            while(sol.digit.back() == 0) sol.digit.pop_back();
            reverse(sol.digit.begin(), sol.digit.end());
            return sol;
        }

        LargeNumber operator = (LargeNumber x) {

            this->digit = x.digit;
            this->sign = x.sign;

            return *this;
        }

        LargeNumber operator = (string x) {

            if(*x.begin() == '-')
                this->sign = 0;

            for(string::iterator it = x.begin(); it != x.end(); ++it) {
                if('0' <= *it && *it <= '9')
                    this->digit.push_back(*it - '0');
            }

            return *this;
        }

        LargeNumber operator = (int x) {
            
            string str = to_string(x);
            *this = str;

            return *this;
        }

        string toString () {

            string str;
            for(auto it = this->digit.begin(); it != this->digit.end(); ++it)
                str.push_back((char)(*it + '0'));

            if(!this->sign)
                str.insert(str.begin(), '-');

            return str;
        }
};

LargeNumber operator >> (istream &in, LargeNumber &x) {
    string tmp;
    in >> tmp;

    if(*tmp.begin() == '-')
        x.sign = 0;

    for(string::iterator it = tmp.begin(); it != tmp.end(); ++it) {
        if('0' <= *it && *it <= '9')
            x.digit.push_back(*it - '0');
    }

    return x;
}

ostream &operator << (ostream &out, LargeNumber x) {
    if(!x.sign)
        out << '-';
    for(vector<short>::iterator it = x.digit.begin(); it != x.digit.end(); ++it)
        out << *it;
    return out;
}

bool operator == (const LargeNumber& x1, const LargeNumber& x2) {
    if(x1.sign != x2.sign)
        return 0;

    auto it1 = x1.digit.begin(), it2 = x2.digit.begin();

    for(; it1 != x1.digit.end() && it2 != x2.digit.end(); ++it1, ++it2)
        if(*it1 != *it2)
            return 0;

    return 1;
}

bool operator != (const LargeNumber& x1, const LargeNumber& x2) {
    return !(x1 == x2);
}

bool operator > (const LargeNumber& x1, const LargeNumber& x2) {
    if(x1.sign != x2.sign)
        return x1.sign > x2.sign;

    if(x1.digit.size() != x2.digit.size())
        return x1.digit.size() > x2.digit.size();
    
    auto it1 = x1.digit.begin(), it2 = x2.digit.begin();

    while(*it1 == *it2 && it1 != x1.digit.end() && it2 != x2.digit.end())
        ++it1, ++it2;
    
    return *it1 > *it2;
}

bool operator < (const LargeNumber& x1, const LargeNumber& x2) {
    if(x1.sign != x2.sign)
        return x1.sign < x2.sign;

    if(x1.digit.size() != x2.digit.size())
        return x1.digit.size() < x2.digit.size();
    
    auto it1 = x1.digit.begin(), it2 = x2.digit.begin();

    while(*it1 == *it2 && it1 != x1.digit.end() && it2 != x2.digit.end())
        ++it1, ++it2;
    
    return *it1 < *it2;
}

bool operator >= (const LargeNumber& x1, const LargeNumber& x2) {
    return !(x1 < x2);
}

bool operator <= (const LargeNumber& x1, const LargeNumber& x2) {
    return !(x1 > x2);
}