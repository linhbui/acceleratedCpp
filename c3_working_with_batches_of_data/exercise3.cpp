// Count the occurrences of each distinct word in the input

#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main() {
    unordered_map<string, int> mymap;
    string word;
    cout << "Enter words" << endl;

    // put the words into map
    while (cin >> word) {
        if (mymap.find(word) == mymap.end()) {
            mymap[word] = 1;
        } else {
            ++mymap[word];
        }
    }

    // print out results
    for (auto it : mymap) {
        std::cout << " " << it.first << ":" << it.second;
    }
    std::cout << std::endl;
    return 0;

}
