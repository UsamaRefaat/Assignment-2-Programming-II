#include "BigReal.h"
#include <bits/stdc++.h>
using namespace std;
//------------------------------------------------------------------------------------------------------------------
// check valid numbers
bool BigReal :: isValid(string s) {
    int ctr{};
    bool pos = false,ng = false;
    int ind_p{},ind_n{};
    // check if there is alpha char
    for (int i = 0; i < s.length(); ++i) {
        if (isalpha(s[i])) return false;
        if (s[i] == '.')
            ctr++; // count number of points
        if (s[i] == '+') { pos = true; ind_p = i;}
        if (s[i] == '-') {ng = true; ind_n = i;}
        if (s[i] == ' ') {return false;}
    }
    if (ng && pos || number.length()==0) {
        return false; // if there is any sign only invalid
    } else if (pos) {
        if(ind_p) {return false;} // check if the positive position is wrong not at index zero
        else return true;
    } else if (ng) {
        if(ind_n) {return false;} // check if the negative position is wrong not at index zero
        else return true;
    }
    // if there is more than point
    if (ctr > 1) {
        return false;
    } else {
        return true;
    }
}
//------------------------------------------------------------------------------------------------------------------
BigReal ::BigReal(string number)  : number(number) {
    if (!isValid(number)) {not_valid();}
    // if there is negative sign , set number to negative category
    if (this->number[0] == '-') {
        neg = true;
    }
    // if for example the is .900 , so add zero at the beginning
    if (this->number[0] == '.') {
        this->number = "0"+this->number;
    }
    // if for example the is +.900 , so remove the sign and add zero at the beginning
    else if (this->number[0] == '+' && this->number[1] == '.') {
        this->number.erase(this->number.begin());
        this->number = "0"+this->number;
    }
    // if for example the is -.900 , so remove the sign and add zero at the beginning
    else if (this->number[0] == '-' && this->number[1] == '.') {
        this->number.erase(this->number.begin());
        this->number = "0"+this->number;
        this->number = "-"+this->number;
    } else if (this->number[0] == '+') {this->number.erase(this->number.begin());}
}
//------------------------------------------------------------------------------------------------------------------
bool BigReal :: operator>( BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    bool neg1;
    neg1 = a.neg;
    // check if first number is negative and second is positive so greater operator return false
    if (neg && !neg1) return false;
    // check if first number is positive and second is negative so greater operator return true
    else if (!neg && neg1) return true;
    // check if both numbers are positive
    else if (!neg && !neg1) {
        int ctr1{},ctr2{},ind1{},ind2{};
        for (int i = 0; i < number.length(); ++i) {
            if (number[i] == '.') {
                ind1 = i; // get point index of 1st number
                break;
            } else {
                ctr1++; // count number of digits of 1st number
            }
        }
        for (int i = 0; i < a.number.length(); ++i) {
            if (a.number[i] == '.') {
                ind2 = i; // get point index of 2nd number
                break;
            } else {
                ctr2++; // count number of digits of 2nd number
            }
        }
        // check if number of digits is greater in 1st number so return true
        if (ctr1 > ctr2) {return true;}
        // check if number of digits is greater in 2nd number so return false
        else if (ctr1 < ctr2) {return false;}
        // if number of digits are equal so we will check each digit
        else {
            for (int i = 0; i < ind1; ++i) {
                // if digits of first number are greater return true
                if ((number[i]-'0') > (a.number[i] - '0')) {
                    return true;
                }
                // if digits of second are greater return true
                else if ((number[i]-'0') < (a.number[i] - '0')) {
                    return false;
                }
            }
            // get the size of each number before decimal point
            int diff1 = number.length()-ind1,diff2 = a.number.length()-ind2;
           // if second number difference in length is greater or equal
            if (diff1 <= diff2) {
                // loop from the index of decimal point of 1st number and check if each digit is greater
                for (int i = ind1+1; i < number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) { // if first number is greater , then return true
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) { // if second number is greater ,  then return false
                        return false;
                    }
                }
                // else return true (equal)
                return false;
            }
                // if first number difference in length is greater
            else {
                int k{};
                // loop from the index of decimal point of 2nd number and check if each digit is greater
                for (int i = ind2+1; i < a.number.length(); ++i) {
                    if ((number[i]-'0') > (a.number[i] - '0')) { // if first number is greater , then return true
                        return true;
                    } else if ((number[i]-'0') < (a.number[i] - '0')) { // if second number is greater ,  then return false
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
    }
    // if both numbers are negative
    else {
        string temp1="",temp2="";
        // loops begins after the sign (i=1)
        for (int i = 1; i < number.length(); ++i) {temp1 += number[i];}
        for (int i = 1; i < a.number.length(); ++i) {temp2 += a.number[i];}
        BigReal b(temp1);
        BigReal c(temp2);
        // check if 1st number is greater , then return false "as we are working on negative"
        if (b > c) {
            return false;
        }
        //otherwise return true
        return true;
    }
}
//------------------------------------------------------------------------------------------------------------------
bool BigReal :: operator<(BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    // point to greater than operator to check if first number is greater so return true
    if (!(*this > a)) return true;
    // point to equal comparison operator to check if both numbers are equal so return false
    if (*this == a) return false;
    else return false;
}
bool BigReal :: operator==(BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    // if it is not greater and not smaller , so its equal
    if (!(*this > a) && !(*this < a)) {
        return true;
    } else {
        return false;
    }
}
//------------------------------------------------------------------------------------------------------------------
BigReal BigReal :: operator+(BigReal a) {
    if (!(isValid(number) && isValid(a.number))) {
        not_valid();
        exit(0);
    }
    BigReal c;
    // check if both numbers are negative
    if (neg && a.neg) {
        string temp1="",temp2="";
        // loop begins after the sign '-'
        for (int i = 1; i < number.length(); ++i) {temp1 += number[i];}
        for (int i = 1; i < a.number.length(); ++i) {temp2 += a.number[i];}
        BigReal b(temp1);
        BigReal d(temp2);
        // add them and return the result with '-' sign at the beginning
        c = b+d;
        c.number = "-"+c.number;
        return c;
    }
    // check if first number is negative and second is positive
    else if (neg && !a.neg) {
        // erase the sign to work on the number without conflict
        number.erase(number.begin());
        neg = false;
        // points to minus operator and subtract the second from the first and return the result with '-' sign at the beginning
        c = a - *this;
        number = "-"+number; neg = true;
        return c;
    }
    // check if first number is positive and second is negative
    else if (!neg && a.neg) {
        // erase the sign to work on the number without conflict
        a.number.erase(a.number.begin());
        a.neg = false;
        // points to minus operator and subtract the first from the second and return the result with '-' sign at the beginning
        c = *this - a;
        a.number = "-"+a.number; a.neg = true;
        return c;
    }
    int ind1{},ind2{};
    // get the index of the decimal point of first number
    for (int i = 0; i < number.length(); ++i) {
        if (number[i] == '.') {
            ind1 = i;
            break;
        }
    }
    // get the index of the decimal point of second number
    for (int i = 0; i < a.number.length(); ++i) {
        if (a.number[i] == '.') {
            ind2 = i;
            break;
        }
    }
    // check if the first number is whole integer and second has a decimal floating point
    if (!ind1 && ind2) {
        bool ok = false;
        int car{};
        // if the decimal point of the second number is before the end of the first number
        if (ind2 <= number.length()) {
            // put the digits after the point in the result
            for (int i = a.number.length()-1; i >= ind2; --i) {
                c.number += a.number[i];
            }
            // get the digits before the decimal point of the second number
            string n_num (number.length()-ind2,'0');
            for (int i = 0; i < ind2; ++i) {
                n_num += a.number[i];
            }
            for (int i = number.length()-1; i >= 0; i--) {
                // apply summation digit by digit after converting chars to numbers
                int sum = (number[i] - '0')+(n_num[i] - '0');
                sum += car; // add the carry to the whole sum
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1; // carry up one
                }
            }
        }
        // if the decimal point place pf first number is after the first number whole size
        else {
            // loop begins from the second number end and decrement to the point
            for (int i = a.number.length()-1; i >= ind2; --i) {
                c.number += a.number[i]; // put the digits after the point of the 2nd number in the result
            }
            // get the digits of first number
            string n_num (ind2-number.length(),'0');
            for (int i = 0; i < number.length(); ++i) {
                n_num += number[i];
            }

            for (int i = n_num.length()-1; i >= 0; i--) {
                // apply summation digit by digit after converting chars to numbers
                int sum = (n_num[i] - '0')+(a.number[i] - '0');
                sum += car; // add the carry to the whole sum
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1; // carry up one
                }
            }
        }
        // if there is a remaining carry , add it to the result
        if (car) c.number += (car + '0');
        reverse(c.number.begin(),c.number.end());
        return c;
    }
    // check if the second number is whole integer and the first number has decimal floating point
    else if (ind1 && !ind2) {
        c = a + *this; // point to the plus operator but after swapping both number
        return c;
    }
    // check if both numbers are whole integers
    else if (!ind1 && !ind2) {
        // if first number size is greater
        if (number.length() >= a.number.length()) {
            string n_num(number.length()-a.number.length(),'0');
            //get the digits of the second number
            for (int i = 0; i < a.number.length(); ++i) {
                n_num += a.number[i];
            }
            int car{};
            for (int i = number.length()-1; i >= 0;i--) {
                // apply summation digit by digit after converting chars to numbers
                int sum = (n_num[i] - '0')+(number[i] - '0');
                sum += car; // add the carry to the whole sum
                if (sum < 10) {
                    c.number += (sum + '0');
                    car = 0;
                } else {
                    string ch = to_string(sum);
                    c.number += ch[1];
                    car = 1; // carry up one
                }
            }
            // if there is a remaining carry , add it to the result
            if (car) c.number += '1';
            // reverse to get the number in the right form as we are working by "decrement loop"
            reverse(c.number.begin(),c.number.end());
            return c;
        }
        // if second number size is greater
        else if (number.length() < a.number.length()) {
            c = a + *this; // point to the plus operator but after swapping both number
            return c;
        }
    }
    // check if index of the point of 1st number is after the one of the 2nd
    else if (ind1 >= ind2) {
        //  get the difference
        int h = abs(ind1-ind2);
        // get the digits of 2nd number
        string n_num(h,'0');
        for (int i = 0; i < a.number.length(); ++i) {
            n_num += a.number[i];
        }
        int car{};
        int k = number.length();
        // check if first number size is greater than second number
        if (number.length() > n_num.length()) {
            // put the digits of first number in result from the size of the 2nd number digits (from the end and decrement)
            for (int i = number.length()-1; i >= n_num.length() ; i--) {
                c.number += number[i];
                k = i;
            }
        }
        // check if second number size is greater
        else {
            // put the digits of second number in result from the size of the 1st number  (from the end and decrement)
            for (int i = n_num.length()-1; i >= number.length() ; i--) {
                c.number += n_num[i];
                k = i;
            }
        }

        for (int i = k-1; i >= 0; i--) {
            if (number[i] == '.') {
                c.number += '.'; // put the decimal point in its exact place
                continue;
            }
            // apply summation digit by digit after converting chars to numbers
            int sum = (number[i] - '0')+(n_num[i] - '0');
            sum += car; // add the carry to the whole sum
            if (sum < 10) {
                c.number += (sum + '0');
                car = 0;
            } else {
                string ch = to_string(sum);
                c.number += ch[1];
                car = 1; // carry up one
            }
        }
        // if there is a remaining carry , add it to the result
        if (car) c.number += (car + '0');
        // reverse to get the number in the right form as we are working by "decrement loop"
        reverse(c.number.begin(),c.number.end());
        return c;
    }
    // check if  ind2> ind1 (the point of second number after the one of the first)
    else {
        c = a + *this; // point to plus operator after swapping both numbers
        return c;
    }
}

//------------------------------------------------------------------------------------------------------------------
// overloading operator minus to work on two BigReal
BigReal BigReal::operator-(BigReal a) {
    bool neg1;
    BigReal c;
    neg1 = a.neg;
    //check if the two number are positive
    if(!neg && !neg1) {
        // check if first number greater than or equal second number
        if ((*this > a)||(*this == a)) {
            if (!(isValid(number) && isValid(a.number))) {
                not_valid();
                exit(0);
            }
            int ind1{},ind2{};
            // getting the index of the decimal point of 1st Number
            for (int i = 0; i < number.length(); ++i) {
                if (number[i] == '.') {
                    ind1 = i;
                    break;
                }
            }
            //getting the index of the decimal point of 2nd Number
            for (int i = 0; i < a.number.length(); ++i) {
                if (a.number[i] == '.') {
                    ind2 = i;
                    break;
                }
            }
            bool inte = false;
            // if there are no decimal point in both number
            if (!ind1 && !ind2) {inte = true;}
            // if there is decimal point in 2nd number , put point to the 1st
            if (!ind1) {ind1=number.length(); number += ".0";}
            // if there is decimal point in 1st number , put point to the 2nd
            if (!ind2) {ind2 = a.number.length(); a.number += ".0";}
            // loop to balance size of both numbers after point
            while (number.length() - ind1 < a.number.length() - ind2) {
                number += '0';
            }
            // loop to balance size of both numbers after point
            while (a.number.length() - ind2 < number.length() - ind1) {
                a.number += '0';
            }
            // loop to balance size of both numbers before point if point of 1st is after of 2nd
            if (ind1 > ind2) {
                int loop = ind1 - ind2;
                while (loop--) {
                    a.number = '0' + a.number;
                }
            }
                // loop to balance size of both numbers before point if point of 1st is before of 2nd
            else if (ind2 > ind1) {
                int loop = ind2 - ind1;
                while (loop--) {
                    number = '0' + number;
                }

            }
            int borrow = 0;
            int diff;
            for (int i = number.length() - 1; i >= 0; i--) {
                if (number[i] == '.') {
                    // if two integers without decimal points , so ignore it
                    if (inte) {continue;}
                    // put the decimal point in its exact place in the result
                    c.number = '.' + c.number;
                    continue;
                }
                // convert char to number
                int num1 = (number[i] - '0');
                int num2 = (a.number[i] - '0');
                diff = num1 - num2 - borrow;
                if (diff < 0) {
                    diff += 10;
                    borrow = 1; // borrow one from neighbour digit
                } else {
                    borrow = 0;
                }
                c.number = char(diff + '0') + c.number;
            }
           // remove any leading zero at the beginning
            while (c.number.length() > 1 && c.number[0] == '0' && c.number[1] != '.') {
                c.number = c.number.substr(1);
            }
            // check if integers remove back of number (0)
            if (inte) {c.number.erase(c.number.end()-1);}
            return c;
        }
        // check if 2nd number is greater than first number , point to minus after swapping number and add '-' to the result
        else if ((*this < a)) {
            c = a - *this;
            c.number = '-' + c.number;
            return c;
        }
    }
    // check if first is negative and second is positive , remove sign , point to plus operator ,add them and add '-' to the result
    else if (neg && !neg1) {
        number.erase(number.begin()); neg = false;
        c = *this + a;
        number = "-"+number; neg = true;
        c.number = "-" + c.number;
        return c;
    }
    // check if first is positive and second is negative , remove sign , point to plus operator, add them and return the result
    else if (!neg && neg1) {
        a.number.erase(a.number.begin()); a.neg = false;
        c = *this + a;
        a.number = "-"+a.number; a.neg = true;
        return c;
    }
    // check if both numbers are negative , remove signs and point to minus operator , add them and add '-' to the result
    else if (neg && neg1) {
        a.number.erase(a.number.begin()); a.neg = false;
        number.erase(number.begin()); neg = false;
        c = a - *this;
        number = "-"+number; neg = true;
        a.number = "-"+a.number; a.neg = true;
        return c;
    }
}
//------------------------------------------------------------------------------------------------------------------

// overloading insertion operator to print the bigreal
ostream & operator << (ostream& out, BigReal a) {
    return out << a.number << endl;
}
//------------------------------------------------------------------------------------------------------------------
//                                              THE END
//------------------------------------------------------------------------------------------------------------------
