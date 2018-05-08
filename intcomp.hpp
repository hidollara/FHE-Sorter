#pragma once

#include "sorter.hpp"

class IntComparator : public Comparator<int> {
public:
    std::pair<int, int> compare(int a, int b);
};