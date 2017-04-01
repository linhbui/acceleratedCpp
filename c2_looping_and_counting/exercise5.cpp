// Make a triangle, a square and a rectangle
#include <iostream>

using std::cout;
using std::string;
using std::endl;

int main() {
    // Makes a triangle
    int pad = 3;
    int starsCount = 1;
    string pads;
    string stars;
    while (pad != 0) {
        pads = string(pad, ' ');
        stars = string(starsCount, '*');
        cout << pads + stars + pads;
        cout << endl;
        starsCount += 2;
        --pad;
    }
    cout << endl;

    // Makes a square
    string row(5, '*');
    for (int i = 0; i != 5; ++i) {
        cout << row;
        cout << endl;
    }
    cout << endl;

    // Makes a rectangle
    const int rows = 7;
    for (int i = 0; i != rows; ++i) {
        cout << row;
        cout << endl;
    }
    return 0;
}