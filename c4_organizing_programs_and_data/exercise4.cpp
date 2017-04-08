// Calculate the square of int value up to a number
// Write 2 columns, use setw to line the values up nicely

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

void print_squares(int number) {
    int width = 1;
    int curr = number * number;
    while (curr != 0) {
        width++;
        curr /= 10;
    }
    for (int i = 1; i <= number; ++i) {
        cout << i << setw(width) << i * i << endl;
    }
}

int main() {
    cout << "Input number: " << endl;
    int number;
    cin >> number;

    print_squares(number);
    return 0;
}
