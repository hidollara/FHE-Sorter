#pragma once

#include "HElib/src/FHE.h"
#include "encrypter.hpp"
#include "sorter.hpp"

class FHEComparator : public Comparator<Ctxt> {
    Encrypter encrypter;
public:
    FHEComparator(Encrypter e) : Comparator<Ctxt>(), encrypter(e) {}
    std::pair<Ctxt, Ctxt> compare(const Ctxt &a, const Ctxt &b) const;
};
