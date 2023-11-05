// File: A2_21_20221153_10.cpp
// Purpose: For C++ training
// Author: Mostafa Mohamed
// Section: 21
// ID: 20221153
// TA: Rana Abdelkader
// Date: 27 Oct 2023

using namespace std;
#include <bits/stdc++.h>

int main() {
    cout<<"Please attach .txt to every filename."<<endl;
    string dictfile, filename, output;
    cout << "Enter the Dictionary file name: ";
    cin >> dictfile;
    cout << "Enter the filename: ";
    cin >> filename;
    cout << "Enter the output filename: ";
    cin >> output;
    wifstream dictStr(dictfile);
    wifstream inputStr(filename);
    wofstream outputStr(output);
    if (!dictStr.is_open() || !inputStr.is_open() || !outputStr.is_open()) {
        cout << "Error opening one or more files." << endl;
        return 0;
    }
    map<wstring, vector<wstring>> dict;
    wstring word, line1;
    wstring delimiter = L"=";
    while (getline(dictStr, line1)) {
        size_t pos = line1.find(delimiter);
        if (pos != wstring::npos) {
            wstring key = line1.substr(0, pos);
            wstring values = line1.substr(pos + 1);
            // split values into a vector
            wstringstream ss(values);
            wstring value;
            vector<wstring> alternatives;
            while (getline(ss, value, L',')) {
                alternatives.push_back(value);
            }
            dict[key] = alternatives;
        }
    }
    wstring line;
    while (getline(inputStr, line)) {
        wstring modified_line;
        wstring word2;
        for (auto c : line) {
            if (c == L' ' || c == L'.' || c == L',' || c == L'?' || c == L'!' || c == L':') {
                if (!word2.empty()) {
                    if (dict.count(word2)) {
                        int rand_ind = rand() % dict[word2].size();
                        modified_line += dict[word2][rand_ind];
                    } else {
                        modified_line += word2;
                    }
                    word2.clear();
                }
                modified_line += c;
            } else {
                word2 += c;
            }
        }
        if (!word2.empty()) {
            if (dict.count(word2)) {
                int rand_ind = rand() % dict[word2].size();
                modified_line += dict[word2][rand_ind];
            } else {
                modified_line += word2;
            }
        }
        outputStr << modified_line << endl;
    }
    dictStr.close();
    inputStr.close();
    outputStr.close();
    cout << "Text replacement completed. The modified text is saved to " << output << endl;
}