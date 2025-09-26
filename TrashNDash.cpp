#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// function to load user points
map<string,int> loadData() {
    map<string,int> goofyGremlins; // stores users + their points
    ifstream infile("users.txt");
    string sillyName; int sillyPoints;
    while (infile >> sillyName >> sillyPoints) {
        goofyGremlins[sillyName] = sillyPoints;
    }
    return goofyGremlins;
}
// function to save user points
void saveData(map<string,int> &goofyGremlins) {
    ofstream outfile("users.txt");
    for (auto &u : goofyGremlins) {
        outfile << u.first << " " << u.second << "\n";
    }
}
// function to show rewards based on points

void showRewards(int sillyPoints) {
    cout << "\n-- Rewards --\n";
    if (sillyPoints >= 100) cout << " Eco Hero Badge unlocked!\n";
    if (sillyPoints >= 70) cout << "20% supermarket voucher available!\n";
    if (sillyPoints >= 50) cout << "Free coffee coupon available!\n";
    if (sillyPoints >= 30) cout << "Free bus ride ticket available!\n";
    if (sillyPoints < 30) cout << "Collect more to unlock your first reward!\n";
}
// function to show the leaderboard
void showLeaderboard(map<string,int> &goofyGremlins) {
    cout << "\n=== Leaderboard: Top Recyclers ===\n";

// put map into a vector so we can sort
    vector<pair<string,int>> ranking(goofyGremlins.begin(), goofyGremlins.end());

// sort by points, highest first
    sort(ranking.begin(), ranking.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

// show top 5 users (or fewer if less exist)
    int rank = 1;
    for (auto &entry : ranking) {
        cout << rank << ". " << entry.first << " — " << entry.second << " pts\n";
        if (rank++ == 5) break; // stop at top 5
    }
}
int main() {
    map<string,int> goofyGremlins = loadData();
    string sillyUser;
    cout << "=== Welcome to TrashNDash ===\n";
    cout << "Enter your username buddy :) : ";
    cin >> sillyUser;

// check if user already exists
    if (goofyGremlins.find(sillyUser) == goofyGremlins.end()) {
        cout << "New user created! Welcome to the community, " << sillyUser << ".\n";
        goofyGremlins[sillyUser] = 0;
    } else {
        cout << "Welcome back,  " << sillyUser << "! Your current points: "
             << goofyGremlins[sillyUser] << "\n";
    }
bool keepLoopin = true;
    while (keepLoopin) {
        cout << "\n--- Menu ---\n";
        cout << "1. Recycle items\n";
        cout << "2. Check points\n";
        cout << "3. Redeem rewards\n";
        cout << "4. Leaderboard\n"; // new menu option
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        int sillyChoice;
        cin >> sillyChoice;

if (sillyChoice == 1) {
            int plasticBottles, shinyGlass, thiccMetal;
            cout << "Plastics: "; cin >> plasticBottles;
            cout << "Glass: "; cin >> shinyGlass;
            cout << "Metal: "; cin >> thiccMetal;

            int earnedShmoints = (plasticBottles * 5) + (shinyGlass * 7) + (thiccMetal * 10);
            goofyGremlins[sillyUser] += earnedShmoints;

            cout << "You earned " << earnedShmoints << " pts! Total: "
                 << goofyGremlins[sillyUser] << "\n";
        }
        else if (sillyChoice == 2) {
            cout << "Current points: " << goofyGremlins[sillyUser] << "\n";
        }
        else if (sillyChoice == 3) {
            showRewards(goofyGremlins[sillyUser]);
        }
        else if (sillyChoice == 4) {
            showLeaderboard(goofyGremlins);
        }
        else if (sillyChoice == 5) {
            keepLoopin = false;
            cout << "Goodbye, Warrior! " << sillyUser << "! Keep recycling \n";
        }
        else {
            cout << "Invalid option, silly goose.\n";
        }
    }

saveData(goofyGremlins);
return 0;
}
