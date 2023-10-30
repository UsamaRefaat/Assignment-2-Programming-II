// File: A2-22-20221066-2.cpp
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
int main(){
    string s ;
    getline(cin  , s) ;
    for (int i = 0  ; i < s.size() ; i++)
    {   if ((s[i] == 'h'||s[i]=='H')&&(s[i+1] =='i' || s[i+1] == 'I' ) && (s[i+2] == 'm' ||s[i+2] == 'M' || s[i+2]=='s' || s[i+2] == 'S') && (ispunct(s[i+3]) || s[i+3] ==' '))
        { if (i == 0 ){
                char e = s[i + 3];
                s.erase(i + 3, 1);
                string c = " or her";
                c += e;
                s.insert(i + 3, c);
                i += 10;
            }
            else
            {
                if (ispunct(s[i-1]) || (s[i-1]) == ' ')
                {
                    char e = s[i + 3];
                    s.erase(i + 3, 1);
                    string c = " or her";
                    c += e;
                    s.insert(i + 3, c);
                    i += 10;
                }
            }
        }
        else if ((s[i] == 'h'||s[i]=='H')&&(s[i+1] =='e' || s[i+1] == 'E' ) &&(ispunct(s[i+2]) || s[i+2] ==' ') )
        { if (i == 0) {
                char e = s[i + 2];
                s.erase(i + 2, 1);
                string c = " or she";
                c += e;
                s.insert(i + 2, c);
                i += 9;
            }
            else
            {if (ispunct(s[i-1]) || (s[i-1]) == ' ') {
                    char e = s[i + 2];
                    s.erase(i + 2, 1);
                    string c = " or she";
                    c += e;
                    s.insert(i + 2, c);
                    i += 9;
                }
            }
        }
    }
    cout << s;
    return 0;
}