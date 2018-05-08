#include "intcomp.hpp"
#include "bitonic.hpp"
#include <iostream>

int main() {
    Comparator<int> *c = new IntComparator;
    Sorter<int> *s = new BitonicSorter<int>(c);

    std::vector<int> v{1, 6, 4, 7, 3, 2, 5, 8};
    s->sort(v.begin(), v.end());

    for (auto x : v) std::cout << x << ' ';
    std::cout << std::endl;

    return 0;
}