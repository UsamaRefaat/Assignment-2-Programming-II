//------------------------------------------------------------------
// File:      problem 6.cpp                                        |
// Purpose:   revising & practicing C++ through problem solving.   |
// Author:    Osama Refaat Sayed.                                  |
// Section:   S21                                                  |
// ID:        20221015                                             |
// TA:        Rana Abdelkader                                      |
// Date:      25 Oct 2023                                          |
//------------------------------------------------------------------
#include <iostream>
using namespace std ;

       // convert from binary into integer and print it

       void print_int_to_binary (int n)
           {

            if (n>1)
            {
                print_int_to_binary(n/2);
            }
            cout<<n%2;
            }


        // print all possible permutation (2^k) after adding specific number of digits (k)
        void print_many_numbers(string prefix,int k)
        {
            if (k==0)
            {
                cout<<prefix<<"\n";
            }


            else {
                print_many_numbers(prefix + "0", k - 1);
                print_many_numbers(prefix + "1", k - 1);
            }


        }


int main ()
{
cout<<"Enter the number you want to convert it into binary\n";
    int n ;
    cin>>n;
    print_int_to_binary(n);
    cout<<"\n";

//----------------------------------------------------------

cout<<"Enter the binary number you want it to be followed by suffix\n";
string prefix;
cin>>prefix;

//----------------------------------------------------------

cout<<"Enter suffix length\n";
int k ;
cin>>k;
print_many_numbers(prefix,k);

//----------------------------------------------------------


    return 0;
}