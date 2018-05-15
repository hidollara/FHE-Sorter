#pragma once

#include "HElib/src/FHE.h"

class Encrypter {
    FHEcontext context;
    FHESecKey secretKey;
public:
    const FHEPubKey& publicKey;
    Encrypter(
        long p = 1021, long r = 1,
        long L = 16, long c = 3, long w = 64, long d = 0, long k = 128, long s = 0);
    ZZX getG();
    Ctxt encrypt(int p);
    NTL::ZZ decrypt(Ctxt ct);
};

