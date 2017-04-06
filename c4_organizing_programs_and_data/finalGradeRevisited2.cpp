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
using std::istream;
using std::streamsize;
using std::sort;
using std::max;
using std::vector;
using std::domain_error;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

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

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
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

istream& read(istream& is, Student_info& s) {
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxLen = 0;

    while (read(cin, record)) {
        maxLen = max(maxLen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name
             << string(maxLen - students[i].name.size() + 1, ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
