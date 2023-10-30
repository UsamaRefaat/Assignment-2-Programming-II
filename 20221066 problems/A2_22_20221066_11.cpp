// File: A2-22-20221066-11.cpp
// Purpose: solving the assignment.
// Author: Ziad Tawfik.
// Section: S22.
// ID: 20221066.
// TA: Rana Abd-ELkader.
// Date: 25 Oct 2023
#include <iostream>
#include <fstream>
#include <string>
using namespace std ;
void compareCharacterByCharacter(ifstream& file1, ifstream& file2) {
    string line1, line2;
    int lineNum = 1;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            cout << "Files are different at line " << lineNum << ":\n";
            cout << "File 1: " << line1 << "\n";
            cout << "File 2: " << line2 << "\n";
            return;
        }
        lineNum++;
    }

    if (file1.eof() && file2.eof()) {
        cout << "Files are identical.\n";
    }
}
void compareWordByWord(ifstream& file1, ifstream& file2) {
    string word1, word2;
    int lineNum = 1;
    bool differenceFound = false;
    while (file1 >> word1 && file2 >> word2) {
        if (word1 != word2) {
            cout << "Files are different at line " << lineNum-1 << ":\n";
            cout << "First different word: " << word1 << "\n";
            differenceFound = true;
            break;
        }
        lineNum++;
    }

    if (!differenceFound) {
        if (file1.eof() && file2.eof()) {
            std::cout << "Files are identical.\n";
        }
    }
}

void compareFiles(const string& filename1, const string& filename2, char comparisonType) {
    std::ifstream file1(filename1 , ios::app), file2(filename2 , ios:: app);
    if (comparisonType == 'a') {
        compareCharacterByCharacter(file1, file2);
    } else if (comparisonType == 'b') {
        compareWordByWord(file1, file2);
    }

    file1.close();
    file2.close();
}

int main() {
    string filename1, filename2;
    char comparisonType;
    cout << "Enter the name of the first file: ";
    cin >> filename1;
    cout << "Enter the name of the second file: ";
    cin >> filename2;
    cout << "Enter the comparison type (a for character, b for word): ";
    cin >> comparisonType;
    compareFiles(filename1, filename2, comparisonType);

    return 0;
}