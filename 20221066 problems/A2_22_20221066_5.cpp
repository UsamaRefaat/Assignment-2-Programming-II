// File: A2-22-20221066-5.cpp
// Purpose: solving the assignment.
// Author: Ziad Tawfik.
// Section: S22.
// ID: 20221066.
// TA: Rana Abd-ELkader.
// Date: 25 Oct 2023
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names;
    vector<int> scores;

    while (true) {
        cout << "Enter 1 to add a player." << endl;
        cout << "Enter 2 to print the top 10 players." << endl;
        cout << "Enter 3 to print the highest score of a player." << endl;
        cout << "Enter 4 to stop the program." << endl;

        int option;
        cin >> option;

        if (option == 1) {
            string name;
            int score;
            cout << "Enter player name: ";
            cin >> name;
            cout << "Enter player score: ";
            cin >> score;

            names.push_back(name);
            scores.push_back(score);

            if (names.size() > 10) {
                int minIndex = min_element(scores.begin(), scores.end()) - scores.begin();
                names.erase(names.begin() + minIndex);
                scores.erase(scores.begin() + minIndex);
            }
        }
        else if (option == 2) {
            if (names.empty()) {
                cout << "No players in the list." << endl;
            }
            else {
                vector<int> sortedScores = scores;
                sort(sortedScores.rbegin(), sortedScores.rend());

                cout << "Top 10 players:" << endl;
                for (int i = 0; i < 10 ; ++i) {
                    int score = sortedScores[i];
                    int index = find(scores.begin(), scores.end(), score) - scores.begin();
                    cout << names[index] << " " << score << endl;
                }
            }
        }
        else if (option == 3) {
            string name;
            cout << "Enter player name: ";
            cin >> name;

            bool found = false;
            int highestScore = 0;
            for (size_t i = 0; i < names.size(); ++i) {
                if (names[i] == name) {
                    found = true;
                    highestScore = max(highestScore, scores[i]);
                }
            }

            if (found) {
                cout << "Highest score for player " << name << ": " << highestScore << endl;
            }
            else {
                cout << "The player's name has not been input or is not in the top 10." << endl;
            }
        }
        else if (option == 4) {
            break;
        }

    }

    return 0;
}
