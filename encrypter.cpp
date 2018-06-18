#include "encrypter.hpp"

Encrypter::Encrypter(
        long p, long r, long L, long c, long w, long d, long k, long s) :
    context(FindM(k, L, c, p, d, s, 0), p, r),
    secretKey(context),
    publicKey(secretKey)
{
    buildModChain(context, L, c);
    secretKey.GenSecKey(w);
}

const FHEcontext& Encrypter::getContext() const {
    return context;
}

const ZZX Encrypter::getG() const {
    return context.alMod.getFactorsOverZZ()[0];
}

Ctxt Encrypter::encrypt(int p) const {
    Ctxt ctx(publicKey);
    publicKey.Encrypt(ctx, to_ZZX(p));
    return ctx;
}

NTL::ZZ Encrypter::decrypt(Ctxt ct) const {
    ZZX pt;
    secretKey.Decrypt(pt, ct);
    return pt[0];
}
