#include "intcomp.hpp"

std::pair<int, int> IntComparator::compare(const int &a, const int &b) const {
    std::pair<int, int> ret;
    ret.first = a < b ? a : b;
    ret.second = a > b ? a : b;
    return ret;
}
