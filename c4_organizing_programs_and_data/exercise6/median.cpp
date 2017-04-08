#include <algorithm>
#include <stdexcept>
#include <vector>

using std::sort;
using std::domain_error;
using std::vector;

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