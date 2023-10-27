

#ifndef CLION_PROJECTS_BIGREAL_H
#define CLION_PROJECTS_BIGREAL_H
#include <bits/stdc++.h>
using namespace std;

class bigreal {
private:
    string number;
    bool neg = false;
public:
    bool isValid (string s);
    bigreal() {
        number = "";
    }
    bigreal (string number) : number(number) {
        if (number[0] == '-') {
            neg = true;
        }
    }
    void set_string(string real_number) {
        number = real_number;
        if (number[0] == '-') {
            neg = true;
        }
    }
    void not_valid () {
        cout<<"INVALID NUMBERS";
    }
    bool get_neg() {
        return neg;
    }
    string get_string() {
        return number;
    }
    bigreal operator + ( bigreal a);
    bigreal operator - ( bigreal a);
    bool operator < ( bigreal a);
    bool operator > ( bigreal a);
    bool operator == ( bigreal a);
    friend ostream& operator << (ostream& out, bigreal num);
};


#endif //CLION_PROJECTS_BIGREAL_H
