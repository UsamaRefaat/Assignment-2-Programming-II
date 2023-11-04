// File: A2-22-20221066-8.cpp
// Purpose: solving the assignment.
// Author: Ziad Tawfik.
// Section: S22.
// ID: 20221066.
// TA: Rana Abd-ELkader.
// Date: 25 Oct 2023
#include <iostream>
using namespace std;

void pattern( int l , int len )
{   if (len == 0)
        return;
    pattern( l, len / 2 );                          // above

    for ( int i = 0; i < l  ; i++ ) cout << "  ";
    for ( int i = 0; i < len; i++ ) cout << "* ";        // Central
    cout << endl;

    pattern( l + (len / 2), len / 2 );               //  below
}

int main()
{

    pattern( 0, 8 );
}
