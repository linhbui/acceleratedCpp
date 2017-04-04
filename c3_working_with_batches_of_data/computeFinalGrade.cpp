// Compute final grade based on midterm score, final score and average of homework scores

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

int main() {
    cout << "Your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " + name + "!" << endl;

    // Get midterm and final grade
    cout << "Please enter your midterm and final grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // Ask for all homeworks grades
    cout << "Enter all your homework grades, follow by end-of-file";

    int count = 0;
    double sum = 0;

    double x;

    while (cin >> x) {
        ++count;
        sum += x;
    }

    streamsize precision = cout.precision();

    cout << "Your final grade is "
         << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count
         << setprecision(precision)
         << endl;

    return 0;
}