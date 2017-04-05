#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::sort;
using std::vector;

int main() {
    // Ask for all homeworks grades
    cout << "Enter all your homework grades, follow by end-of-file";

    double x;
    vector<double> grades;

    while (cin >> x) {
        grades.push_back(x);
    }

    typedef vector<double>::size_type vector_size;
    vector_size size = grades.size();

    if (size == 0) {
        cout << "Invalid grades, try again" << endl;
        return 1;
    } else {
        sort(grades.begin(), grades.end());
        vector_size mid = size / 2;
        double median;
        if (size % 2 == 0) {
            median = (grades[mid] + grades[mid-1]) / 2;
        } else {
            median = grades[mid];
        }

        streamsize precision = cout.precision();

        cout << "Your median grade is "
             << setprecision(3)
             << median
             << setprecision(precision)
             << endl;

        return 0;
    }
}
