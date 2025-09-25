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
