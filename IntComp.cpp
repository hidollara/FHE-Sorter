#include "IntComp.hpp"

std::pair<int, int> IntComparator::compare(const int &a, const int &b) const {
    return std::make_pair((a < b ? a : b), (a < b ? b : a));
}
