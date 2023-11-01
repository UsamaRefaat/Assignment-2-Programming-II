

#ifndef CLION_PROJECTS_BIGREAL_H
#define CLION_PROJECTS_BIGREAL_H
#include <bits/stdc++.h>
using namespace std;

class BigReal {
private:
    string number;
    bool neg = false;
public:
    bool isValid (string s);
    BigReal() {
        number = "";
    }
    BigReal (string number);
    void set_string(string real_number) {
        number = real_number;
        if (number[0] == '-') {
            neg = true;
        }
    }
    void not_valid () {
        cout<<"INVALID NUMBERS";
        exit(0);
    }
    bool get_neg() {
        return neg;
    }
    string get_string() {
        return number;
    }
    BigReal operator + ( BigReal a);
    BigReal operator - ( BigReal a);
    bool operator < ( BigReal a);
    bool operator > ( BigReal a);
    bool operator == ( BigReal a);
    friend ostream& operator << (ostream& out, BigReal num);
};


#endif //CLION_PROJECTS_BIGREAL_H
