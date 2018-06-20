#pragma once

#include "HElib/src/FHE.h"

class Encrypter {
    FHEcontext context;
protected:
    FHESecKey secretKey;
    const FHEPubKey& publicKey;
public:
    Encrypter(
        long p = 2, long r = 1,
        long L = 16, long c = 2, long w = 64, long d = 1, long k = 0, long s = 0);
    const FHEcontext& getContext() const;
    const ZZX getG() const;
    Ctxt encrypt(int p) const;
    ZZ decrypt(Ctxt ct) const;
};
