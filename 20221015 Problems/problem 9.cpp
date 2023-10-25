//------------------------------------------------------------------
// File:      problem 9.cpp                                        |
// Purpose:   revising & practicing C++ through problem solving.   |
// Author:    Osama Refaat Sayed.                                  |
// Section:   S21                                                  |
// ID:        20221015                                             |
// TA:        Rana Abdelkader                                      |
// Date:      25 Oct 2023                                          |
//------------------------------------------------------------------
#include <iostream>
using namespace std;
bool teddy_bear_picnic(int n)
{
    int last_digits=(n%10)*((n%100)/10);
    // you begin with a number less than our target
    if (n<42)
        return false;
    //  you begin with the target  // even number so we return half of the number
    else if (n==42                  ||       (n%2==0 && teddy_bear_picnic(n/2)))
        return true;
    // if it is divisible by 3 or 4 multiply the last two digits and return
    else if ((n%3==0 || n%4==0)&& teddy_bear_picnic(n-last_digits))
        return true;
    // if it is divisible by 5 return exactly 42 bears
    else if (n%5==0&& teddy_bear_picnic(n-42))
        return true;
    else
        return false;
}
int main ()
{
    cout<<"Enter number of bears you have\n";
    int n ;
    cin >>n;
//----------------------------------------------------------

    if (teddy_bear_picnic(n))
        cout<<"YOU WIN !!!";
    else
        cout<<"YOU LOSE ...";
//----------------------------------------------------------

    return 0;
}