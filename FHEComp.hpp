#pragma once

#include "HElib/src/FHE.h"
#include "Encrypter.hpp"
#include "Sorter.hpp"

class FHEComparator : public Comparator<Ctxt> {
    const Encrypter &encrypter;
public:
    FHEComparator(const Encrypter &e) : Comparator<Ctxt>(), encrypter(e) {}
    std::pair<Ctxt, Ctxt> compare(const Ctxt &a, const Ctxt &b) const;
};
