// File: A2_21_20221153_1.cpp
// Purpose: For C++ training
// Author: Mostafa Mohamed
// Section: 21
// ID: 20221153
// TA: Rana Abdelkader
// Date: 25 Oct 2023
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    bool space = false;
    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            space = true;
        }
        if (space) {
            ans += s[i];
            space = false;
        } else {
            ans += tolower(s[i]);
        }

    }
    cout<<ans<<endl;
}