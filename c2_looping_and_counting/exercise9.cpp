// ask user to enter 2 numbers, then tell the user which one is larger

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    cout << "First number: ";
    string first;
    cin >> first;
    cout << endl;

    cout << "Second number: ";
    string second;
    cin >> second;
    cout << endl;

    string bigger = first > second ? first : second;
    cout << "The bigger number is " + bigger;
    cout << endl;

    return 0;
}