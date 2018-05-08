#include "intcomp.hpp"

std::pair<int, int> IntComparator::compare(int a, int b) {
    std::pair<int, int> ret;
    ret.first = a < b ? a : b;
    ret.second = a > b ? a : b;
    return ret;
}
