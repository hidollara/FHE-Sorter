#pragma once

#include "Encrypter.hpp"
#include "HElib/src/EncryptedArray.h"

#define BIT_WIDTH 8

class EncArrayEncrypter : public Encrypter {
public:
    const EncryptedArray ea;
    EncArrayEncrypter() : Encrypter(), ea(getContext(), getG()) {}
    Ctxt encrypt(int p) const;
    ZZX decrypt(Ctxt ct) const;
};
