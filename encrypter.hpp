#pragma once

#include "HElib/src/FHE.h"

class Encrypter {
    FHEcontext context;
    FHESecKey secretKey;
public:
    const FHEPubKey& publicKey;
    Encrypter(
        long p = 2, long r = 1,
        long L = 16, long c = 2, long w = 64, long d = 1, long k = 80, long s = 0);
    ZZX getG();
    Ctxt encrypt(int p);
    NTL::ZZ decrypt(Ctxt ct);
};

