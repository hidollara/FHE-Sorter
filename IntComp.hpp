#pragma once

#include "Sorter.hpp"

class IntComparator : public Comparator<int> {
public:
    std::pair<int, int> compare(const int &a, const int &b) const;
};
