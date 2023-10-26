// File: A2_21_20221153_4.cpp
// Purpose: For C++ training
// Author: Mostafa Mohamed
// Section: 21
// ID: 20221153
// TA: Rana Abdelkader
// Date: 25 Oct 2023
#include <bits/stdc++.h>
using namespace std;

vector<bool> generatePrimes(int N) {
    vector<bool> isPrime(N + 1, true);
    for (int p = 2; p * p <= N; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }
    return isPrime;
}

int main() {
    int N;
    cin >> N;
    vector<int>executed(N+1,0);
    vector<bool>isPrime = generatePrimes(N);
    vector<int>ans;
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i] && !executed[i]) {
            for (int j = i+1; j <= N; ++j) {
                if (j % i == 0) {
                    executed[j] = 1;
                }
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (!executed[i]) {
            ans.push_back(i);
        }
    }
    for (auto i : ans) {
        cout<<i<<' ';
    }
}
