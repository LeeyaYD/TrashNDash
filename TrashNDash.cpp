#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

// function to load user points
map<string,int> loadData() {
    map<string,int> users;
    ifstream infile("users.txt");
    string name; int pts;
    while (infile >> name >> pts) {
        users[name] = pts;
    }
    return users;
}
// function to save user points
void saveData(map<string,int> &users){
ofstream outfile("users.txt");

  }
}

