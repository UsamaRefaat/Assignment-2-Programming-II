#include "BigReal.h"
#include <bits/stdc++.h>
using namespace std;

bool BigReal :: isValid(string s) {
    int ctr{};
    bool pos = false,ng = false;
    int ind_p{},ind_n{};
    for (int i = 0; i < s.length(); ++i) {
        if (isalpha(s[i])) return false;
        if (s[i] == '.')
            ctr++;
        if (s[i] == '+') { pos = true; ind_p = i;}
        if (s[i] == '-') {ng = true; ind_n = i;}
        if (s[i] == ' ') {return false;}
    }
    if (ng && pos || number.length()==0) {
        return false;
    } else if (pos) {
        if(ind_p) {return false;}
        else return true;
    } else if (ng) {
        if(ind_n) {return false;}
        else return true;
    }
    if (ctr > 1) {
        return false;
    } else {
        return true;
    }
}
BigReal ::BigReal(string number)  : number(number) {
    if (!isValid(number)) {not_valid();}
    if (this->number[0] == '-') {
        neg = true;
    }
    if (this->number[0] == '.') {
        this->number = "0"+this->number;
    }
    else if (this->number[0] == '+' && this->number[1] == '.') {
        this->number.erase(this->number.begin());
        this->number = "0"+this->number;
    }
    else if (this->number[0] == '-' && this->number[1] == '.') {
        this->number.erase(this->number.begin());
        this->number = "0"+this->number;
        this->number = "-"+this->number;
    } else if (this->number[0] == '+') {this->number.erase(this->number.begin());}
}
bool BigReal :: operator>( BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    bool neg1;
    neg1 = a.neg;
    if (neg && !neg1) return false;
    else if (!neg && neg1) return true;
    else if (!neg && !neg1) {
        int ctr1{},ctr2{},ind1{},ind2{};
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == '.') {
                ind1 = i;
                break;
            } else {
                ctr1++;
            }
        }
        for (int i = 0; i < a.number.length(); ++i) {
            if (a.number[i] == '.') {
                ind2 = i;
                break;
            } else {
                ctr2++;
            }
        }
        if (ctr1 > ctr2) {return true;}
        else if (ctr1 < ctr2) {return false;}
        else {
            for (int i = 0; i < ind1; ++i) {
                if ((number[i]-'0') > (a.number[i] - '0')) {
                    return true;
                } else if ((number[i]-'0') < (a.number[i] - '0')) {
                    return false;
                }
            }
            int diff1 = number.length()-ind1,diff2 = a.number.length()-ind2;
            if (diff1 <= diff2) {
                for (int i = ind1+1; i < number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return false;
                    }
                }
                return false;
            } else {
                int k{};
                for (int i = ind2+1; i < a.number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) {
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) {
                        return false;
                    }
                    k = i;
                }
                for (int i = k+1; i < number.length(); ++i) {
                    if (number[i] - '0' > 0) {
                        return true;
                    }
                }
                return false;
            }
        }
    } else {
        string temp1="",temp2="";
        for (int i = 1; i < number.length(); ++i) {temp1 += number[i];}
        for (int i = 1; i < a.number.length(); ++i) {temp2 += a.number[i];}
        BigReal b(temp1);
        BigReal c(temp2);
        if (b > c) {
            return false;
        }
        return true;
    }
}
bool BigReal :: operator<(BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    if (!(*this > a)) return true;
    if (*this == a) return false;
    else return false;
}
bool BigReal :: operator==(BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    if (!(*this > a) && !(*this < a)) {
        return true;
    } else {
        return false;
    }
}
BigReal BigReal :: operator+(BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    BigReal c;
    if (neg && a.neg) {
        string temp1="",temp2="";
        for (int i = 1; i < number.length(); ++i) {temp1 += number[i];}
        for (int i = 1; i < a.number.length(); ++i) {temp2 += a.number[i];}
        BigReal b(temp1);
        BigReal d(temp2);
        c = b+d; c.number = "-"+c.number;
        return c;
    } else if (neg && !a.neg) {
        number.erase(number.begin());
        neg = false;
        c = a - *this;
        number = "-"+number; neg = true;
        return c;
    } else if (!neg && a.neg) {
        a.number.erase(a.number.begin());
        a.neg = false;
        c = *this - a;
        a.number = "-"+a.number; a.neg = true;
        return c;
    }
    int ind1{},ind2{};
    for (int i = 0; i < number.length(); ++i) {
        if (number[i] == '.') {
            ind1 = i;
            break;
        }
    }
    for (int i = 0; i < a.number.length(); ++i) {
        if (a.number[i] == '.') {
            ind2 = i;
            break;
        }
    }
    if (!ind1 && ind2) {
        bool ok = false;
        int car{};
        if (ind2 <= number.length()) {
            for (int i = a.number.length()-1; i >= ind2; --i) {
                c.number += a.number[i];
            }
            string n_num (number.length()-ind2,'0');
            for (int i = 0; i < ind2; ++i) {
                n_num += a.number[i];
            }
            for (int i = number.length()-1; i >= 0; i--) {
                int sum = (number[i] - '0')+(n_num[i] - '0');
                sum += car;
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1;
                }
            }
        } else {
            for (int i = a.number.length()-1; i >= ind2; --i) {
                c.number += a.number[i];
            }
            string n_num (ind2-number.length(),'0');
            for (int i = 0; i < number.length(); ++i) {
                n_num += number[i];
            }
            for (int i = n_num.length()-1; i >= 0; i--) {
                int sum = (n_num[i] - '0')+(a.number[i] - '0');
                sum += car;
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1;
                }
            }
        }
        if (car) c.number += (car + '0');
        reverse(c.number.begin(),c.number.end());
        return c;
    } else if (ind1 && !ind2) {
        c = a + *this;
        return c;
    } else if (!ind1 && !ind2) {
        if (number.length() >= a.number.length()) {
            string n_num(number.length()-a.number.length(),'0');
            for (int i = 0; i < a.number.length(); ++i) {
                n_num += a.number[i];
            }
            int car{};
            for (int i = number.length()-1; i >= 0;i--) {
                int sum = (n_num[i] - '0')+(number[i] - '0');
                sum += car;
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1;
                }
            }
            if (car) c.number += '1';
            reverse(c.number.begin(),c.number.end());
            return c;
        } else if (number.length() < a.number.length()) {
            c = a + *this;
            return c;
        }
    }
    else if (ind1 >= ind2) {
        int h = abs(ind1-ind2);
        string n_num(h,'0');
        for (int i = 0; i < a.number.length(); ++i) {
            n_num += a.number[i];
        }
        int car{};
        int k = number.length();
        if (number.length() > n_num.length()) {
            for (int i = number.length()-1; i >= n_num.length() ; i--) {
                c.number += number[i];
                k = i;
            }
        } else {
            for (int i = n_num.length()-1; i >= number.length() ; i--) {
                c.number += n_num[i];
                k = i;
            }
        }

        for (int i = k-1; i >= 0; i--) {
            if (number[i] == '.') {
                c.number += '.';
                continue;
            }
            int sum = (number[i] - '0')+(n_num[i] - '0');
            sum += car;
            if (sum < 10) {
                c.number += (sum + '0');
                car = 0;
            } else {
                string ch = to_string(sum);
                c.number += ch[1];
                car = 1;
            }
        }
        if (car) c.number += (car + '0');
        reverse(c.number.begin(),c.number.end());
        return c;
    } else {
        c = a + *this;
        return c;
    }
}
BigReal BigReal::operator-(BigReal a) {
    bool neg1;
    BigReal c;
    neg1 = a.neg;
    if(!neg && !neg1) {
        if ((*this > a)||(*this == a)) {
            if (!(isValid(number) && isValid(a.number))) {
                not_valid();
                exit(0);
            }
            int ind1{},ind2{};
            for (int i = 0; i < number.length(); ++i) {
                if (number[i] == '.') {
                    ind1 = i;
                    break;
                }
            }
            for (int i = 0; i < a.number.length(); ++i) {
                if (a.number[i] == '.') {
                    ind2 = i;
                    break;
                }
            }
            bool inte = false;
            if (!ind1 && !ind2) {inte = true;}
            if (!ind1) {ind1=number.length(); number += ".0";}
            if (!ind2) {ind2 = a.number.length(); a.number += ".0";}
            while (number.length() - ind1 < a.number.length() - ind2) {
                number += '0';
            }

            while (a.number.length() - ind2 < number.length() - ind1) {
                a.number += '0';
            }
            if (ind1 > ind2) {
                int loop = ind1 - ind2;
                while (loop--) {
                    a.number = '0' + a.number;
                }
            } else if (ind2 > ind1) {
                int loop = ind2 - ind1;
                while (loop--) {
                    number = '0' + number;
                }

            }
            int borrow = 0;
            int diff;
            for (int i = number.length() - 1; i >= 0; i--) {
                if (number[i] == '.') {
                    if (inte) {continue;}
                    c.number = '.' + c.number;
                    continue;
                }
                int num1 = (number[i] - '0');
                int num2 = (a.number[i] - '0');
                diff = num1 - num2 - borrow;
                if (diff < 0) {
                    diff += 10;
                    borrow = 1;
                } else {
                    borrow = 0;
                }
                c.number = char(diff + '0') + c.number;
            }
// when the result = 0 it prints more than zero:
            while (c.number.length() > 1 && c.number[0] == '0' && c.number[1] != '.') {
                c.number = c.number.substr(1);
            }
            if (inte) {c.number.erase(c.number.end()-1);}
            return c;
        } else if ((*this < a)) {
            c = a - *this;
            c.number = '-' + c.number;
            return c;
        }
    } else if (neg && !neg1) {
        number.erase(number.begin()); neg = false;
        c = *this + a;
        number = "-"+number; neg = true;
        c.number = "-" + c.number;
        return c;
    } else if (!neg && neg1) {
        a.number.erase(a.number.begin()); a.neg = false;
        c = *this + a;
        a.number = "-"+a.number; a.neg = true;
        return c;
    } else if (neg && neg1) {
        a.number.erase(a.number.begin()); a.neg = false;
        number.erase(number.begin()); neg = false;
        c = a - *this;
        number = "-"+number; neg = true;
        a.number = "-"+a.number; a.neg = true;
        return c;
    }
}
ostream & operator << (ostream& out, BigReal a) {
    return out << a.number << endl;
}
