#include "Student_info.h"
#include "Grade.h"

using std::istream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
    is >> s.name;
    Grade g;
    is >> g.midterm >> g.final;

    read_hw(is, g.homework);
    s.final_grade = grade(g);
    return is;
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

