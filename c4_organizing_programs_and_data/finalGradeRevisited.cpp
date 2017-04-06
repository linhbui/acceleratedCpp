// Compute final grade based on midterm score, final score and average of homework scores

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::istream;
using std::sort;
using std::vector;
using std::domain_error;

double median(vector<double> vec) {
    typedef vector<double>::size_type vector_size;
    vector_size size = vec.size();

    if (size == 0)
        throw domain_error("can't find median of empty vector");

    sort(vec.begin(), vec.end());
    vector_size mid = size / 2;

    if (size % 2 == 0) {
        return (vec[mid] + vec[mid-1]) / 2;
    } else {
        return vec[mid];
    }
}

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& homework) {
    if (homework.size() == 0)
        throw domain_error("homework is empty");
    return grade(midterm, final, median(homework));
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        hw.clear();

        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so input will work for the next student
        in.clear();
    }
    return in;
}

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

    vector<double> homework;
    read_hw(cin, homework);

    try {
        double final_grade = grade(midterm, final, homework);
        streamsize precision = cout.precision();

        cout << "Your final grade is "
             << setprecision(3)
             << final_grade
             << setprecision(precision)
             << endl;
    } catch (domain_error) {
        cout << "You must enter your grade" << endl;
        return 1;
    }

    return 0;
}
