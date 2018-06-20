#include "EncArrayEncrypter.hpp"

Ctxt EncArrayEncrypter::getMSBTrue() const {
    static Ctxt ret = encrypt(1 << (BIT_WIDTH - 1));
    return ret;
}

Ctxt EncArrayEncrypter::getTrue() const {
    static Ctxt ret = encrypt((1 << BIT_WIDTH) - 1);
    return ret;
}

Ctxt EncArrayEncrypter::getFalse() const {
    static Ctxt ret = encrypt(0);
    return ret;
}

Ctxt EncArrayEncrypter::encrypt(int p) const {
    std::vector<long> pt(BIT_WIDTH);

    // encode int to little endian
    for (int i = 0; i < BIT_WIDTH; i++) { pt[(BIT_WIDTH - 1) - i] = p % 2; p >>= 1; }

    for (int i = BIT_WIDTH; i < ea.size(); i++) pt.push_back(0);

    Ctxt ct(publicKey);
    ea.encrypt(ct, publicKey, pt);
    return ct;
}

ZZ EncArrayEncrypter::decrypt(Ctxt ct) const {
    std::vector<long> pt(BIT_WIDTH);
    ea.decrypt(ct, secretKey, pt);

    int p = 0;

    // decode little endian to int
    for (int i = 0; i < BIT_WIDTH; i++) { p <<= 1;  p += pt[i]; }

    return to_ZZ(p);
}
