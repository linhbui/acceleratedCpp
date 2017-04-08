#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>

struct Grade {
    double final, midterm;
    std::vector<double> homework;
};

double grade(const Grade&);
double grade(double, double, const std::vector<double>&);
double grade(double, double, double);

#endif