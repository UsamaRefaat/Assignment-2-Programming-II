// File: A2-22-20221066-8.cpp
// Purpose: solving the assignment.
// Author: Ziad Tawfik.
// Section: S22.
// ID: 20221066.
// TA: Rana Abd-ELkader.
// Date: 25 Oct 2023
#include <bits/stdc++.h>
using namespace std;
# define endl '\n'
# define ll long long
void printStars_spaces(int numStars, int spaces) {
    for (int i = 0  ; i <  spaces ; i++)
    {
        cout << "  "  ;
    }
    for (int c = 0 ; c < numStars ;c++)
    {
        cout << "* ";
    }
    cout << endl ;
}
void pattern(int n, int i) {
    if (n == 1) {
        printStars_spaces(1, i);
        return;
    }

    pattern(n / 2, i);
    printStars_spaces(n, i);
    pattern(n / 2, i + n / 2);
}
int main() {
    pattern(8 ,0) ;
    return 0;
}
