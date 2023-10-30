// BigReal OOP Project.
//TASK 2.

#include "BigReal.h"
using namespace std;
#include <bits/stdc++.h>


int main() {
    bigreal n1 ("11.9000000000000000000000000000000001");
    bigreal n2 ("2333333333339.1134322222222292");
    bigreal n3 = n1 + n2;
    cout << n3;
    n3 = n3 + bigreal ("0.9");
    cout<<n3;
}
