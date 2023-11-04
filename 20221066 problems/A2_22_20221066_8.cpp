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
