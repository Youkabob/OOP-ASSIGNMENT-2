/*
File: A2_S6_20221025_5.cpp
 Purpose: manages a list of up to 10 players and their high scores
 Author: alaa wael mohamed
 Section: s6
 ID: 20221025
 TA: Nardeen Mokhless Khela - Maya Ahmed
 Date: 12 Oct 2023
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
    int choose = 0, size = 0;
    multiset<pair<int, string >> players;

    while (choose != 4) {    // main menu
        cout << "\nplease select option : \n\n";
        cout << "1- add new player\n";
        cout << "2- view top 10 scorers\n";
        cout << "3- view player highest score\n";
        cout << "4- exit\n";
        cout << ">> ";
        cin >> choose;
        int score, mx = 0;
        string player_name;
        switch (choose) {
            case 1:
            start:
                cout << "enter the player name >>";
                cin >> player_name;
                cout << "player's score >>";
                cin >> score;
                // If there are more than 10 players, remove the player with the lowest score
                if ((!players.empty() && players.rbegin()->first < score) || players.size() < 10) {
                    players.insert({score, player_name});
                    if (players.size() > 10) players.erase(players.end());
                }
                char ch;
                cout << "add another player?(y/n)";
                cin >> ch;
                if (ch == 'y') goto start;

                break;
            case 2:
                // Display the top 10 scorers
                for (auto i = players.rbegin(); i != players.rend(); i++) {
                    cout << i->second << " " << i->first << "\n";
                }
                break;
            case 3:
                cout << "enter player's name >>";
                cin >> player_name;
                // Find the highest score for the specified player
                for (auto i: players) {
                    if (i.second == player_name) mx = max(mx, i.first);
                }
                if (mx > 0)
                    cout << mx << "\n";
                else cout << "the player is not from top 10!\n";
                break;
            default:
                break;
        }
    }
}

