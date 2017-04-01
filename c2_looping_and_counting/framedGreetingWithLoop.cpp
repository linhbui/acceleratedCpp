#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "Your name: ";
    string name;
    cin >> name;

    const string greeting = "Hello " + name + "!";

    // Number of blanks surrounding the greeting
    const int pad = 1;

    // Number of rows and columns to write
    const int rows = pad * 2 + 3;
    const string::size_type cols = greeting.size() + pad * 2 + 2;

    // Blank line to separate input line and output
    cout << endl;

    for (int row = 0; row != rows; ++row) {
        string::size_type col = 0;

        while (col != cols) {
            if (row == pad + 1 && col == pad + 1) {
                cout << greeting;
                col += greeting.size();
            } else {
                // Check if we are at the border
                if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                ++col;
            }
        }
        cout << endl;
    }

    return 0;
}
