#include <stdexcept>
#include <vector>
#include "Grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;

double grade(const Grade& g) {
    return grade(g.midterm, g.final, g.homework);
}

double grade(double midterm, double final, const vector<double>& homework) {
    if (homework.size() == 0)
        throw domain_error("homework is empty");
    return grade(midterm, final, median(homework));
}

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

