#include "Encrypter.hpp"
#include "FHEComp.hpp"
#include "Bitonic.hpp"
#include "OddEven.hpp"
#include <iostream>

Encrypter e;

void run(Sorter<Ctxt> *s) {
    std::vector<Ctxt> v{
        e.encrypt(0),
        e.encrypt(1),
        e.encrypt(1),
        e.encrypt(0),
        e.encrypt(1),
        e.encrypt(0),
        e.encrypt(1),
        e.encrypt(0),
    };

    for (auto x : v) std::cout << e.decrypt(x)[0] << ' ';
    std::cout << std::endl;

    s->sort(v.begin(), v.end());

    for (auto x : v) std::cout << e.decrypt(x)[0] << ' ';
    std::cout << std::endl;
}

int main() {
    Comparator<Ctxt> *c = new FHEComparator(e);
    Sorter<Ctxt> *s;

    std::cout << "bitonic sort" << std::endl;
    s = new BitonicSorter<Ctxt>(c);
    run(s);

    std::cout << "oddeven sort" << std::endl;
    s = new OddEvenSorter<Ctxt>(c);
    run(s);

    return 0;
}
