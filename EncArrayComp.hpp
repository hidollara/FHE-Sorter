#pragma once

#include "HElib/src/FHE.h"
#include "EncArrayEncrypter.hpp"
#include "Sorter.hpp"

class EncArrayComparator : public Comparator<Ctxt> {
    const EncArrayEncrypter &encrypter;
public:
    EncArrayComparator(const EncArrayEncrypter &e) : Comparator<Ctxt>(), encrypter(e) {}
    std::pair<Ctxt, Ctxt> compare(const Ctxt &a, const Ctxt &b) const;
};
