#include <iostream>
#include <bits/stdc++.h>
#include "machine_simulator.h"
using namespace std;

int main() {
    string file_n;
    cout<<"Enter the file name: ";
    cin >> file_n;
    ifstream file(file_n);
    if (!file.is_open()) {
        cerr << "Error opening the file." << endl;
        return 1;
    }
    MachineSimulator a;
    string line;
    while (getline(file,line)) {
        string ins="";
        for (int i = 0; i < line.length(); ++i) {
            if (line[i] == ' ' || line[i] == 'x' || i == 0) {
                continue;
            } else {
                if (line[i] == '0') {
                    if (line[i-1] == 'x' || line[i-1] == '0') {
                        ins += line[i];
                    }
                } else {
                    ins += line[i];
                }
            }
        }
        a.instructions.push_back(ins);
    }
    a.run_program();
    file.close();
}
