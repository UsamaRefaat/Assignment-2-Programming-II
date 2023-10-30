// File: A2-22-20221066-5.cpp
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
int main() {
    deque<pair<int , string>> p;
    while (true) {
        cout << "Enter 1 to add a player." << endl ;
        cout << "Enter 2 to print 10 top players." <<endl;
        cout << "Enter 3 to print highest score of a player." << endl ;
        cout << "Enter 4 to stop program." << endl ;

        int option;
        cin >> option;
        if (option == 1 )
        {   string name ;
            cin >> name ;
            int score;
            cin >>score ;
            if (p.size() < 10)
            {
                p.emplace_back(score , name) ;

                sort(p.begin(), p.end()) ;
            }

            else if (p.size() ==  10)
            {

                if (score > p.back().first)
                {
                    p.pop_back() ;
                    p.emplace_back(score , name) ;
                    cout << "The player is added succefully." << endl ;
                }
                else if (score < p.back().first){
                    cout << "The player was not added. " << endl  ;
                }

            }

        }
        else if (option == 2)
        {
            sort(p.rbegin(), p.rend()) ;
            for (auto f : p)
                cout   << f.second << " " << f.first << endl ;
            cout << endl ;
        }
        else if (option == 3){
            string c ;
            cin >> c ;
            bool ok = 0  ;
            int z ;
            for (int i = 0; i < p.size(); ++i) {
                if (c == p[i].second)
                {    z = p[i].first ;
                    ok = 1 ;
                }
            }
            if (ok == 0)
            {
                cout << "the player's name has not been input or is not in the top 10." << endl ;
            }
            else
                cout << z << endl ;
        }
        else
            break;
    }
    return 0;
}
