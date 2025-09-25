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
