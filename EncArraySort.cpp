#include "EncArrayEncrypter.hpp"
#include "EncArrayComp.hpp"
#include "Bitonic.hpp"
#include "OddEven.hpp"
#include <iostream>

EncArrayEncrypter e(2);

void run(Sorter<Ctxt> *s) {
    std::vector<Ctxt> v{
        e.encrypt(2),
        e.encrypt(0),
        e.encrypt(1),
        e.encrypt(3),
    };

    for (auto x : v) std::cout << e.decrypt(x) << ' ';
    std::cout << std::endl;

    s->sort(v.begin(), v.end());

    for (auto x : v) std::cout << e.decrypt(x) << ' ';
    std::cout << std::endl;
}

int main() {
    Comparator<Ctxt> *c = new EncArrayComparator(e);
    Sorter<Ctxt> *s;

    s = new BitonicSorter<Ctxt>(c);
    run(s);

    s = new OddEvenSorter<Ctxt>(c);
    run(s);

    return 0;
}
