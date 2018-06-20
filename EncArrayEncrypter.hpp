#pragma once

#include "Encrypter.hpp"
#include "HElib/src/EncryptedArray.h"

class EncArrayEncrypter : public Encrypter {
public:
    const int l;
    const EncryptedArray ea;
    EncArrayEncrypter(int l) : Encrypter(), ea(getContext(), getG()), l(l) {}
    Ctxt getMSBTrue() const;
    Ctxt getTrue() const;
    Ctxt getFalse() const;
    Ctxt encrypt(int p) const;
    ZZ decrypt(Ctxt ct) const;
};
