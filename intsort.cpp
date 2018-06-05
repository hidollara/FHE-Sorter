#include "intcomp.hpp"
#include "bitonic.hpp"
#include "oddeven.hpp"
#include <iostream>

void run(Sorter<int> *s) {
    std::vector<int> v{1, 6, 4, 7, 3, 2, 5, 8};

    for (auto x : v) std::cout << x << ' ';
    std::cout << std::endl;

    s->sort(v.begin(), v.end());

    for (auto x : v) std::cout << x << ' ';
    std::cout << std::endl;
}

int main() {
    Comparator<int> *c = new IntComparator;
    Sorter<int> *s;

    s = new BitonicSorter<int>(c);
    run(s);

    s = new OddEvenSorter<int>(c);
    run(s);

    return 0;
}

