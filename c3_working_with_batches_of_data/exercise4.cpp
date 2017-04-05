// report the length of the longest string and shortest string of the input

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::min;
using std::max;

int main() {
    vector<string> words;

    cout << "Input words" << endl;
    string word;
    while (cin >> word) {
        words.push_back(word);
    }

    vector<string>::size_type size = words.size();
    if (size == 0) {
        cout << "Invalid input" << endl;
        return 1;
    } else {
        string::size_type maxLen = words[0].size();
        string::size_type minLen = words[0].size();

        for (string w : words) {
            maxLen = max(w.size(), maxLen);
            minLen = min(w.size(), minLen);
        }

        cout << "The smallest word length is " << minLen << endl
             << "The largest word length is " << maxLen << endl;

        return 0;
    }
}
