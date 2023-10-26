// File: A2_21_20221153_7.cpp
// Purpose: For C++ training
// Author: Mostafa Mohamed
// Section: 21
// ID: 20221153
// TA: Rana Abdelkader
// Date: 25 Oct 2023

#include <bits/stdc++.h>
using namespace std;
struct dominoT {
    int leftDots;
    int rightDots;
};

bool FormsDominoChain(vector<dominoT>& dominos, int index, vector<bool>& used, vector<dominoT>& chain) {
    if (index == dominos.size()) {
        return true;
    }

    for (int i = 0; i < dominos.size(); i++) {
        if (!used[i]) {
            if (index == 0 || dominos[i].leftDots == chain[index - 1].rightDots) {
                used[i] = true;
                chain[index] = dominos[i];
                if (FormsDominoChain(dominos, index + 1, used, chain)) {
                    return true;
                }
                used[i] = false;
            }
        }
    }
    return false;
}

int main() {
    cout << "Enter the number of dominos: ";
    int n;
    cin >> n;
    vector<dominoT> dominoSet(n);
    vector<bool> used(n, false);
    vector<dominoT> chain(n);
    cout << "Enter the left and right dots respectively:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> dominoSet[i].leftDots >> dominoSet[i].rightDots;
    }
    if (FormsDominoChain(dominoSet, 0, used, chain)) {
        cout << "Dominos chain: ";
        for (int i = 0; i < n; i++) {
            cout << chain[i].leftDots << '|' << chain[i].rightDots;
            if (i != n - 1) {
                cout << " - ";
            }
        }
    } else {
        cout << "IMPOSSIBLE";
    }
}
